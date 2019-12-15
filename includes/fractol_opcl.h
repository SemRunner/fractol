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

# define FR_FLOAT float

typedef struct	s_complex_cl
{
	FR_FLOAT		re;
	FR_FLOAT		im;
}				t_complex_cl;

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

	FR_FLOAT		zoom;
	FR_FLOAT		m_x;
	FR_FLOAT		m_y;
	int			max_iter;
	t_complex_cl	k;
	t_complex_cl	factor;

	int			height;
	int			width;
}						t_fractol_cl;

int						init_cl(t_opcl *opcl);
void					terminate(t_opcl *opcl, int flag);

#endif
