/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 10:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 16:35:12 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>
#include "fractol.h"

int		mouse_move(int x, int y, t_fractol *f)
{
	double	coef_x = (double)x / (double)WIDTH;		//coef_x = 0..1
	double	coef_y = (double)y / (double)HEIGHT;
	if (x < 0 || x >= WIDTH)
		return (1);
	if (y < 0 || y >= HEIGHT)
		return (1);
	f->mouse_x = x;
	f->mouse_y = y;
	if (f->type_fractol == FR_JULIA)
	{
		f->k = init_complex(
			4 * ((double)x / (double)WIDTH - 0.5),
			4 * ((double)(HEIGHT - y) / (double)HEIGHT - 0.5));
		printf("%Lf, %Lf\n", f->k.re, f->k.im);
		ft_printf("%d %d\n", x, y);
		draw_fractol(f);
	}
	// else if (f->type_fractol == FR_MANDEL)
	// {
	// 	f->max = init_complex(
	// 		2.0 - (coef_x - 0.5) * 4.0,
	// 		2.0 + (coef_y - 0.5) * 4.0);
	// 	f->min = init_complex(
	// 		-2.0 - (coef_x - 0.5) * 4.0,
	// 		-2.0 + (coef_y - 0.5) * 4.0);
	// 	draw_fractol(f);
	// }
	return (1); 
}

int		main(int argc, char **argv)
{
	t_mlx	m;
	t_fractol	f;

	//max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;

	fractol_init(&f);
	tmlx_initialize(&m, HEIGHT, WIDTH);
	tmlx_create_mlx(&m, "fractol");
	f.m = &m;
	draw_fractol(&f);
	if (argc > 3)
		ft_printf("%s\n", argv[1]);
	ft_printf("test\n");
	ft_printf("start fractol\n");	
	mlx_put_image_to_window(m.ptr, m.win, m.main_im, 0, 0);
	mlx_key_hook(m.win, fract_keyhook, (void*)&f);
	mlx_hook(m.win, 6, 0, mouse_move, &f);
	mlx_loop(m.ptr);
	//tmlx_destroy(&m, 0);
}
