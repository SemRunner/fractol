/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_proj_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:46:34 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/29 20:39:26 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	get_iso_point_to_draw(t_mlx *m, int i)
{
	t_point		p;
	int			shift_x;
	int			shift_y;

	p = m->map_points[i];
	shift_x = m->width / 2;
	shift_y = m->height / 2;
	p.x -= shift_x;
	p.y -= shift_y;
	iso(m, &(p.x), &(p.y), p.z);
	p.x += shift_x;
	p.y += shift_y;
	return (p);
}

static t_point	get_zproj_point_to_draw(t_mlx *m, int i)
{
	t_point		p;

	p = m->map_points[i];
	return (p);
}

static t_point	get_xproj_point_to_draw(t_mlx *m, int i)
{
	t_point		p;
	int			shift_z;
	int			prev;

	p = m->map_points[i];
	shift_z = m->width / 2;
	prev = p.x;
	p.x = p.z + shift_z;
	p.z = -prev;
	return (p);
}

static t_point	get_yproj_point_to_draw(t_mlx *m, int i)
{
	t_point		p;
	int			shift_z;
	int			prev;

	p = m->map_points[i];
	shift_z = m->height / 2;
	prev = p.y;
	p.y = -p.z + shift_z;
	p.z = -prev;
	return (p);
}

t_point			get_proj_point_to_draw(t_mlx *m, int i)
{
	if (m->projection_type == 1)
		return (get_zproj_point_to_draw(m, i));
	else if (m->projection_type == 2)
		return (get_xproj_point_to_draw(m, i));
	else if (m->projection_type == 3)
		return (get_yproj_point_to_draw(m, i));
	return (get_iso_point_to_draw(m, i));
}
