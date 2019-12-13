/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 22:24:23 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 23:17:41 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_opcl.h"

void		set_fractol_cl(t_fractol *f, t_fractol_cl *f_cl)
{
	f_cl->type_fractol = f->type_fractol;
	f_cl->type_color = f->type_color;
	f_cl->zoom = f->zoom;
	f_cl->m_x = f->m_x;
	f_cl->m_y = f->m_y;
	f_cl->max_iter = f->max_iter;
	f_cl->factor = f->factor;
	f_cl->k = f->k;
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

	opcl->total_s = WIDTH * HEIGHT;
	opcl->local_s = 250;
	set_fractol_cl(f, &f_cl);
	set_args(opcl, &f_cl);
}
