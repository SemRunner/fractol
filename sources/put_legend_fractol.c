/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_legend_fractol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:04:02 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 19:42:00 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_fractol_keybindings(t_fractol *f)
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
	mlx_string_put(f->m->ptr, f->m->win, 10, 220, FDF_GRAY, "ESC, Q: exit");
}

void		put_fractol_legend(t_fractol *f)
{
	char str[50];

	str[0] = '\0';
	mlx_string_put(f->m->ptr, f->m->win, 10, 10, FDF_WHITE,
					"FRACT'OL CURRENT CONDITIONS:");
	ft_printf("%yTYPE OF FRACTOL: ", str);
	if (f->type_fractol == 0)
		ft_printf("%yMANDEL", str);
	else if (f->type_fractol == 1)
		ft_printf("%yJULIA", str);
	else if (f->type_fractol == 2)
		ft_printf("%yBURNING SHIP", str);
	else if (f->type_fractol == 3)
		ft_printf("%yCEL_MAN", str);
	else if (f->type_fractol == 4)
		ft_printf("%yTEST", str);
	else if (f->type_fractol == 5)
		ft_printf("%yCEL_PER", str);
	mlx_string_put(f->m->ptr, f->m->win, 10, 30, FDF_LGREEN, str);
	str[0] = '\0';
	ft_printf("%yITERATIONS: %d", str, f->max_iter);
	mlx_string_put(f->m->ptr, f->m->win, 10, 50, FDF_LGREEN, str);
	put_fractol_keybindings(f);
}