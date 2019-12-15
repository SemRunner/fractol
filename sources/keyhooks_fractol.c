/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_fractol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:31:49 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 14:49:00 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	else if (keycode == FDF_KEY_7)
		f->type_fractol = 6;
	else if (keycode == FDF_Z)
		fractol_reset(f);
	else
		return (0);
	return (1);
}

int			fract_keyhook2(int keycode, t_fractol *f)
{
	if (keycode == FDF_KEY_PLUS || keycode == FDF_KEY_NP_PLUS)
		f->max_iter += (int)((double)(f->max_iter) * 0.2) > 0 ?
						(int)((double)(f->max_iter)) * 0.2 : 1;
	else if ((keycode == FDF_KEY_MINUS || keycode == FDF_KEY_NP_MINUS)
				&& f->max_iter > 2)
		f->max_iter -= (int)((double)(f->max_iter) * 0.2) > 0 ?
						(int)((double)(f->max_iter)) * 0.2 : 1;
	else if (keycode == FDF_KEY_W)
		f->show_legend = (f->show_legend + 1) % 3;
	if (keycode == FDF_KEY_X)
		f->type_fractol = (f->type_fractol + 1) % COUNT_FRACTOLS;
	else if (keycode == FDF_KEY_C)
		f->type_color = (f->type_color + 1) % 4;
	else if (keycode == FDF_KEY_UP || keycode == FDF_KEY_DOWN)
		zoom_fractol(f, keycode);
	else if (keycode == FDF_KEY_A)
		f->type_device = (f->type_device + 1) % 2;
	else
		return (0);
	return (1);
}

int			fract_keyhook(int keycode, void *fr)
{
	t_fractol *f;

	f = fr;
	if (keycode == FDF_KEY_Q || keycode == FDF_KEY_ESC)
	{
		tmlx_destroy(f->m, 0);
		terminate(f->opcl, 3);
	}
	else
	{
		fract_keyhook1(keycode, f);
		fract_keyhook2(keycode, f);
	}
	if (f->type_device == 0)
		draw_fractol(f);
	else
		draw_cl(f->opcl, f);
	return (0);
}
