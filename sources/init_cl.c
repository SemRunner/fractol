/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:55:09 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 13:31:20 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_opcl.h"

static void	free_cl(t_opcl *opcl)
{
	if (opcl->context)
		clReleaseContext(opcl->context);
	if (opcl->queue)
		clReleaseCommandQueue(opcl->queue);
	if (opcl->program)
		clReleaseProgram(opcl->program);
	if (opcl->kernel)
		clReleaseKernel(opcl->kernel);
	if (opcl->buf)
		clReleaseMemObject(opcl->buf);
}

void		terminate(t_opcl *opcl, int flag)
{
	if (flag == CL_ERROR)
		ft_printf("%wOpenCL Error\n", 2);
	else if (flag == STD_ERROR)
		ft_printf("%wFile read error\n", 2);
	else if (flag == 2)
		ft_printf("%wError\n", 2);
	free_cl(opcl);
	if (flag == CL_ERROR || flag == STD_ERROR || flag == 2)
		exit(-1);
	else
		exit(0);
}

static void	get_kernel(t_opcl *opcl)
{
	int		ret;
	char	buf[100000];

	ret = clBuildProgram(opcl->program, 1, &opcl->dev, "-I includes", 0, 0);
	if (CL_SUCCESS != ret)
	{
		clGetProgramBuildInfo(opcl->program, opcl->dev,
			CL_PROGRAM_BUILD_LOG, 100000, &buf, NULL);
		ft_printf("%s", buf);
		terminate(opcl, CL_ERROR);
	}
	if (!(opcl->kernel = clCreateKernel(opcl->program,
										"draw_fractol_cl", &ret)))
		terminate(opcl, CL_ERROR);
}

static int	get_device(t_opcl *opcl)
{
	int				ret;
	cl_platform_id	platformid;
	cl_uint			pltf_num;
	cl_uint			dev_num;

	if ((ret = clGetPlatformIDs(0, 0, &pltf_num)) != CL_SUCCESS)
		terminate(opcl, CL_ERROR);
	if ((ret |= clGetPlatformIDs(pltf_num, &platformid, 0)) != CL_SUCCESS)
		terminate(opcl, CL_ERROR);
	if ((ret |= clGetDeviceIDs(platformid,
		CL_DEVICE_TYPE_GPU, 0, 0, &dev_num)) != CL_SUCCESS)
		terminate(opcl, CL_ERROR);
	if ((ret |= clGetDeviceIDs(platformid,
		CL_DEVICE_TYPE_GPU, dev_num, &opcl->dev, 0)) != CL_SUCCESS)
		terminate(opcl, CL_ERROR);
	return (1);
}

int			init_cl(t_opcl *opcl)
{
	int		ret;
	char	*src;

	if (!(get_device(opcl)))
		return (0);
	if (!(opcl->context = clCreateContext(0, 1, &opcl->dev, 0, 0, &ret)))
		terminate(opcl, CL_ERROR);
	if (!(opcl->queue = clCreateCommandQueue(opcl->context,
											opcl->dev, 0, &ret)))
		terminate(opcl, CL_ERROR);
	opcl->buf = clCreateBuffer(opcl->context, CL_MEM_WRITE_ONLY,
								WIDTH * HEIGHT * 4, 0, &ret);
	if (ret != CL_SUCCESS)
		terminate(opcl, CL_ERROR);
	if (!(src = load_src("sources/calc.cl")))
		terminate(opcl, STD_ERROR);
	if (!(opcl->program = clCreateProgramWithSource(opcl->context,
		1, (const char**)&src, NULL, &ret)))
		terminate(opcl, CL_ERROR);
	ft_memdel((void**)&src);
	get_kernel(opcl);
	return (1);
}
