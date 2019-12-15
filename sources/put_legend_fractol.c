/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_legend_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:04:02 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 14:52:55 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_background_legend(t_fractol *f)
{
	int		i;
	int		j;

	if (f->show_legend != 1)
		return ;
	i = -1;
	while (++i < 390)
	{
		j = -1;
		while (++j < 300)
		{
			putpixel(f->m, i, j, 0x101010);
		}
	}
}

static void		put_fractol_keybindings(t_fractol *f)
{
	mlx_string_put(f->m->ptr, f->m->win, 10, 80, FDF_GRAY, "KEYS BINDINGS:");
	mlx_string_put(f->m->ptr, f->m->win, 10, 100, FDF_GRAY,
					"UP/DOWN, SCROLLS: zoom");
	mlx_string_put(f->m->ptr, f->m->win, 10, 120, FDF_GRAY,
					"LEFT BUT: move fractal");
	mlx_string_put(f->m->ptr, f->m->win, 10, 140, FDF_GRAY,
					"+/-: count iterations");
	mlx_string_put(f->m->ptr, f->m->win, 10, 160, FDF_GRAY,
					"numbers, X: change type fractal");
	mlx_string_put(f->m->ptr, f->m->win, 10, 180, FDF_GRAY, "C: change color");
	mlx_string_put(f->m->ptr, f->m->win, 10, 200, FDF_GRAY, "Z: reset fractal");
	mlx_string_put(f->m->ptr, f->m->win, 10, 220, FDF_GRAY, "A: change device");
	mlx_string_put(f->m->ptr, f->m->win, 10, 240, FDF_GRAY, "W: show legend");
	mlx_string_put(f->m->ptr, f->m->win, 10, 260, FDF_GRAY, "ESC, Q: exit");
}

static void		put_type_fractol_legend(t_fractol *f)
{
	char str[100];

	str[0] = '\0';
	mlx_string_put(f->m->ptr, f->m->win, 10, 10, FDF_WHITE,
					"FRACT'OL CURRENT CONDITIONS:");
	ft_printf("%yTYPE OF FRACTOL: ", str);
	if (f->type_fractol == FR_MANDEL)
		ft_printf("%yMANDEL", str);
	else if (f->type_fractol == FR_JULIA)
		ft_printf("%yJULIA", str);
	else if (f->type_fractol == FR_BRN_SP)
		ft_printf("%yBURNING SHIP", str);
	else if (f->type_fractol == FR_CEL_MAN)
		ft_printf("%yCEL_MAN", str);
	else if (f->type_fractol == FR_TEST1)
		ft_printf("%yTEST", str);
	else if (f->type_fractol == FR_CEL_PER)
		ft_printf("%yCEL_PER", str);
	else if (f->type_fractol == FR_SPIDER)
		ft_printf("%yCEL_SPIDER", str);
	mlx_string_put(f->m->ptr, f->m->win, 10, 30, FDF_LGREEN, str);
}

void			put_fractol_legend(t_fractol *f)
{
	char str[100];

	if (f->show_legend == 2)
		return ;
	put_type_fractol_legend(f);
	str[0] = '\0';
	ft_printf("%yDEVICE: ", str);
	if (f->type_device == 0)
		ft_printf("%yDEVICE: CPU", str);
	else if (f->type_device == 1)
		ft_printf("%yDEVICE: GPU", str);
	ft_printf("%y, ITERATIONS: %d", str, f->max_iter);
	mlx_string_put(f->m->ptr, f->m->win, 10, 50, FDF_LGREEN, str);
	put_fractol_keybindings(f);
}
