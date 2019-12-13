/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_opcl.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:50:18 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 22:37:33 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_OPENCL_H
# define FRACTOL_OPENCL_H
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

# define CL_ERROR 0
# define STD_ERROR 1

typedef struct 			s_opcl
{
	cl_device_id		dev;
	cl_command_queue	queue;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_mem				buf;
	size_t				total_s;
	size_t				local_s;
}						t_opcl;

typedef struct			s_fractol_cl
{
	int			type_fractol;
	int			type_color;

	double		zoom;
	double		m_x;
	double		m_y;
	int			max_iter;
	t_complex	k;
	t_complex	factor;
}						t_fractol_cl;

#endif
