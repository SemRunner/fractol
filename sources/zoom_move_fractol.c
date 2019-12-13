/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_move_fractol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:32:14 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 19:42:10 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			in_frontiers(int x, int y, t_fractol *f)
{
	if (x < 0 || x >= f->m->width)
		return (0);
	else if (y < 0 || y >= f->m->height)
		return (0);
	return (1);
}

void		zoom_fractol(t_fractol *f, int keycode)
{
	if (keycode == FDF_KEY_UP || keycode == FDF_SCROLL_D)
	{
		f->zoom *= 1.2;
		f->factor.re -= (f->m_x - f->mouse_x) * 1.2 / f->zoom;
		f->factor.im -= (f->m_y - f->mouse_y) * 1.2 / f->zoom;
		f->m_x = f->mouse_x;
		f->m_y = f->mouse_y;
	}
	else if (keycode == FDF_KEY_DOWN || keycode == FDF_SCROLL_U)
	{
		f->zoom /= 1.2;
		f->factor.re -= (f->m_x - f->mouse_x) / 1.2 / f->zoom;
		f->factor.im -= (f->m_y - f->mouse_y) / 1.2 / f->zoom;
		f->m_x = f->mouse_x;
		f->m_y = f->mouse_y;
	}
}

void		move_fractol(int x, int y, t_fractol *f)
{
	f->factor.re -= (x - f->m_xx) / f->zoom;
	f->factor.im += (f->m_yy - y) / f->zoom;
	f->m_xx = x;
	f->m_yy = y;
}
