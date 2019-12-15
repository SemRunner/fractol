/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:24:23 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 13:14:17 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_opcl.h"

void		set_fractol_cl(t_fractol *f, t_fractol_cl *f_cl)
{
	f_cl->type_fractol = f->type_fractol;
	f_cl->type_color = f->type_color;
	f_cl->zoom = (FR_FLOAT)f->zoom;
	f_cl->m_x = (FR_FLOAT)f->m_x;
	f_cl->m_y = (FR_FLOAT)f->m_y;
	f_cl->max_iter = f->max_iter;
	f_cl->factor.re = (FR_FLOAT)f->factor.re;
	f_cl->factor.im = (FR_FLOAT)f->factor.im;
	f_cl->k.re = (FR_FLOAT)f->k.re;
	f_cl->k.im = (FR_FLOAT)f->k.im;
	f_cl->height = f->m->height;
	f_cl->width = f->m->width;
}

void		set_args(t_opcl *opcl, t_fractol_cl *f_cl)
{
	cl_int		ret;

	ret = clSetKernelArg(opcl->kernel, 0, sizeof(cl_mem), &opcl->buf);
	ret |= clSetKernelArg(opcl->kernel, 1, sizeof(t_fractol_cl), f_cl);
	if (ret != CL_SUCCESS)
		terminate(opcl, CL_ERROR);
}

void		execute_kernel(t_opcl *opcl, t_fractol *f)
{
	t_fractol_cl	f_cl;
	int				ret;

	opcl->total_s = WIDTH * HEIGHT;
	opcl->local_s = 250;
	set_fractol_cl(f, &f_cl);
	set_args(opcl, &f_cl);
	ret = clEnqueueNDRangeKernel(opcl->queue, opcl->kernel, 1,
			NULL, &opcl->total_s, NULL, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		terminate(opcl, CL_ERROR);
}

void		draw_cl(t_opcl *opcl, t_fractol *f)
{
	execute_kernel(opcl, f);
	clEnqueueReadBuffer(opcl->queue, opcl->buf, CL_TRUE, 0,
		WIDTH * HEIGHT * 4, f->m->data_mainim, 0, NULL, NULL);
	mlx_clear_window(f->m->ptr, f->m->win);
	draw_background_legend(f);
	draw_main_image(f->m);
	put_fractol_legend(f);
}
