/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_fractol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:31:49 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 19:41:06 by odrinkwa         ###   ########.fr       */
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
		ft_printf("%Lf, %Lf\n", f->k.re, f->k.im);
		ft_printf("%d %d\n", x, y);
		draw_fractol(f);
	}
	if (f->in_move)
	{
		move_fractol(x, y, f);
		draw_fractol(f);
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
	draw_fractol(f);
	return (1);
}

int			mouse_release(int key, int x, int y, t_fractol *f)
{
	if (x && y)
		;
	if (key == FDF_MOUSE_LEFT)
		f->in_move = 0;
	draw_fractol(f);
	return (1);
}

int			fract_keyhook1(int keycode, t_fractol *f)
{
	if (keycode == FDF_KEY_1)
		f->type_fractol = 0;
	else if (keycode == FDF_KEY_2)
		f->type_fractol = 1;
	else if (keycode == FDF_KEY_3)
		f->type_fractol = 2;
	else if (keycode == FDF_KEY_4)
		f->type_fractol = 3;
	else if (keycode == FDF_KEY_5)
		f->type_fractol = 4;
	else if (keycode == FDF_KEY_6)
		f->type_fractol = 5;
	else if (keycode == FDF_Z)
		fractol_reset(f);
	else
		return (0);
	return (1);
}

int			fract_keyhook(int keycode, void *fr)
{
	t_fractol *f;

	f = fr;
	ft_printf("%d\n", keycode);
	if (keycode == FDF_KEY_Q || keycode == FDF_KEY_ESC)
		tmlx_destroy(f->m, 0);
	else if (keycode == FDF_KEY_PLUS)
		f->max_iter += (int)((double)(f->max_iter) * 0.2) > 0 ?
						(int)((double)(f->max_iter)) * 0.2 : 1;
	else if (keycode == FDF_KEY_MINUS && f->max_iter > 2)
		f->max_iter -= (int)((double)(f->max_iter) * 0.2) > 0 ?
						(int)((double)(f->max_iter)) * 0.2 : 1;
	else if (keycode == FDF_KEY_X)
		f->type_fractol = (f->type_fractol + 1) % COUNT_FRACTOLS;
	else if (keycode == FDF_KEY_C)
		f->type_color = (f->type_color + 1) % 4;
	else if (keycode == FDF_KEY_UP || keycode == FDF_KEY_DOWN)
		zoom_fractol(f, keycode);
	else
		fract_keyhook1(keycode, f);
	draw_fractol(f);
	ft_printf("max_iter = %d\n", f->max_iter);
	return (0);
}
