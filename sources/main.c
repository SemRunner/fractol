/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 15:29:35 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>
#include "fractol.h"
#include "fractol_opcl.h"

void	fractal_usage(void)
{
	ft_printf("usage: ./fractol [type fractol]\n");
	ft_printf("type fractol:\n");
	ft_printf("1   --  Mandelbrot\n");
	ft_printf("2   --  Julia\n");
	ft_printf("3   --  Burning ship\n");
	ft_printf("4   --  Celtic mandelbrot\n");
	ft_printf("5   --  Testing 1\n");
	ft_printf("6   --  Celtic perpendicular\n");
	ft_printf("7   --  Spider\n");
	exit(0);
}

void	check_arguments(t_fractol *f, int argc, char **argv)
{
	int		type_fractol;

	if (argc != 2)
		fractal_usage();
	if (!ft_isint(argv[1]))
		fractal_usage();
	type_fractol = ft_atoi(argv[1]);
	if (type_fractol < 1 || type_fractol > COUNT_FRACTOLS)
		fractal_usage();
	f->type_fractol = type_fractol - 1;
}

int		main(int argc, char **argv)
{
	t_mlx		m;
	t_fractol	f;
	t_opcl		opcl;

	fractol_init(&f);
	check_arguments(&f, argc, argv);
	init_opcl(&opcl);
	init_cl(&opcl);
	tmlx_initialize(&m, WIDTH, HEIGHT);
	if (tmlx_create_mlx(&m, "fractol") == 0)
		terminate(&opcl, 2);
	f.m = &m;
	f.opcl = &opcl;
	if (f.type_device == 0)
		draw_fractol(&f);
	else
		draw_cl(f.opcl, &f);
	mlx_key_hook(m.win, fract_keyhook, (void*)&f);
	mlx_hook(m.win, 6, 0, mouse_move, &f);
	mlx_hook(m.win, 4, 0, mouse_press, &f);
	mlx_hook(m.win, 5, 0, mouse_release, &f);
	mlx_loop(m.ptr);
}
