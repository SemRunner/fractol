/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:33:18 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 13:33:20 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_move(int x, int y, t_fractol *f)
{
	if (!in_frontiers(x, y, f))
		return (1);
	f->mouse_x = x;
	f->mouse_y = y;
	if (f->type_fractol == FR_JULIA)
	{
		f->k = init_complex(
			4 * ((double)x / (double)WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / (double)HEIGHT - 0.5));
		if (f->type_device == 0)
			draw_fractol(f);
		else
			draw_cl(f->opcl, f);
	}
	if (f->in_move)
	{
		move_fractol(x, y, f);
		if (f->type_device == 0)
			draw_fractol(f);
		else
			draw_cl(f->opcl, f);
	}
	return (1);
}

int			mouse_press(int key, int x, int y, t_fractol *f)
{
	if (!in_frontiers(x, y, f))
		return (1);
	f->mouse_x = x;
	f->mouse_y = y;
	if (key == FDF_SCROLL_D || key == FDF_SCROLL_U)
		zoom_fractol(f, key);
	else if (key == FDF_MOUSE_LEFT)
	{
		f->in_move = 1;
		f->m_xx = x;
		f->m_yy = y;
	}
	if (f->type_device == 0)
		draw_fractol(f);
	else
		draw_cl(f->opcl, f);
	return (1);
}

int			mouse_release(int key, int x, int y, t_fractol *f)
{
	if (x && y)
		;
	if (key == FDF_MOUSE_LEFT)
		f->in_move = 0;
	if (f->type_device == 0)
		draw_fractol(f);
	else
		draw_cl(f->opcl, f);
	return (1);
}
