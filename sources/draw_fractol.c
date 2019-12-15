/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:02:57 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 12:33:14 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			set_fractol_color(int iter, int max_iter, int type_color)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)iter / (double)max_iter;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow(1 - t, 3) * t * 255);
	if (type_color == 0)
		return ((red << 16) | (green << 8) | blue);
	else if (type_color == 1)
		return ((red << 16) | (blue << 8) | green);
	else if (type_color == 2)
		return ((blue << 16) | (green << 8) | red);
	else
		return ((blue << 16) | (red << 8) | green);
}

int			iterate_fractol_point(t_fractol *f)
{
	t_complex	z;
	int			iter;

	z = f->c;
	iter = 0;
	if (f->type_fractol == FR_MANDEL)
		iter = cycle_mandel(f, z);
	else if (f->type_fractol == FR_JULIA)
		iter = cycle_julia(f, z);
	else if (f->type_fractol == FR_BRN_SP)
		iter = cycle_brn_sp(f, z);
	else if (f->type_fractol == FR_CEL_MAN)
		iter = cycle_cel_man(f, z);
	else if (f->type_fractol == FR_TEST1)
		iter = cycle_test1(f, z);
	else if (f->type_fractol == FR_CEL_PER)
		iter = cycle_cel_per(f, z);
	else if (f->type_fractol == FR_SPIDER)
		iter = cycle_spider(f, z);
	return (iter);
}

void		draw_fractol(t_fractol *f)
{
	int			x;
	int			y;
	int			iter;

	y = -1;
	while (++y < f->m->height)
	{
		f->c.im = (y - f->m_y) / f->zoom + f->factor.im;
		x = -1;
		while (++x < f->m->width)
		{
			f->c.re = (x - f->m_x) / f->zoom + f->factor.re;
			iter = iterate_fractol_point(f);
			putpixel(
				f->m,
				x, y,
				set_fractol_color(iter, f->max_iter, f->type_color));
		}
	}
	draw_background_legend(f);
	mlx_clear_window(f->m->ptr, f->m->win);
	draw_main_image(f->m);
	put_fractol_legend(f);
}
