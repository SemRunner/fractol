/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:11:45 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/18 16:50:17 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

void	tmlx_destroy(t_mlx *m, int value_exit)
{
	if (m->main_im != NULL)
		mlx_destroy_image(m->ptr, m->main_im);
	if (m->win != NULL)
		mlx_destroy_window(m->ptr, m->win);
	if (m->ptr != NULL)
		ft_memdel((void**)&(m->ptr));
	if (m->map != NULL)
		ft_memdel((void**)&(m->map));
	if (m->map_points != NULL)
		ft_memdel((void**)&(m->map_points));
	errno = 200;
	if (value_exit != -10)
		exit(value_exit);
}

void	reset_map(t_mlx *m)
{
	m->zoom_coef = 19;
	m->h_coef = 40;
	m->zoom = 0.6666667;
	m->h = 1;
	m->x_angle = 0;
	m->y_angle = 0;
	m->z_angle = 0;
	m->projection_type = 0;
	m->type_color_spectrum = 1;
	m->camera_x = 0;
	m->camera_y = 0;
}

void	tmlx_initialize(t_mlx *m, int x, int y)
{
	m->bits_pixel = sizeof(int) * 8;
	m->size_line = x * (int)sizeof(int);
	m->endian = 0;
	m->ptr = NULL;
	m->win = NULL;
	m->main_im = NULL;
	m->data_mainim = NULL;
	m->map = NULL;
	m->map_points = NULL;
	m->width = x;
	m->height = y;
	m->map_x = 0;
	m->map_y = 0;
	m->quantity_points = 0;
	reset_map(m);
	m->rotate_prec = FDF_ANGLE_ROTATE_PRECISION;
	m->angle_projection_type = 0;
	m->projection_type = 0;
}

int		tmlx_create_mlx(t_mlx *m, char *title)
{
	if (!(m->ptr = mlx_init()))
		tmlx_destroy(m, -10);
	else if (!(m->win = mlx_new_window(m->ptr, m->width, m->height, title)))
		tmlx_destroy(m, -10);
	else if (!(m->main_im = mlx_new_image(m->ptr, m->width, m->height)))
		tmlx_destroy(m, -10);
	else
	{
		m->data_mainim = (int*)mlx_get_data_addr(m->main_im,
							&(m->bits_pixel), &(m->size_line), &(m->endian));
		return (1);
	}
	return (0);
}
