/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 22:04:25 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>
#include "fractol.h"
#include "fractol_opcl.h"

int		main(int argc, char **argv)
{
	t_mlx	m;
	t_fractol	f;
	t_opcl		opcl;

	fractol_init(&f);
	init_cl(&opcl);
	tmlx_initialize(&m, HEIGHT, WIDTH);
	tmlx_create_mlx(&m, "fractol");
	f.m = &m;
	draw_fractol(&f);
	if (argc > 3)
		ft_printf("%s\n", argv[1]);
	ft_printf("test\n");
	ft_printf("start fractol\n");
	mlx_key_hook(m.win, fract_keyhook, (void*)&f);
	mlx_hook(m.win, 6, 0, mouse_move, &f);
	mlx_hook(m.win, 4, 0, mouse_press, &f);
	mlx_hook(m.win, 5, 0, mouse_release, &f);
	mlx_loop(m.ptr);
}

// TODO добавить обработку argv
// TODO добавить usage
