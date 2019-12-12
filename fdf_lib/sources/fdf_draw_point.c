/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:24:32 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 15:24:33 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			putpoint(t_mlx *m, int i)
{
	t_point tmp;

	tmp = get_point_to_draw(m, i);
	putpixel(m, tmp.x, tmp.y, tmp.color);
}

t_point			get_point_to_draw(t_mlx *m, int i)
{
	t_point		res;

	res = get_proj_point_to_draw(m, i);
	res.x += m->camera_x;
	res.y += m->camera_y;
	return (res);
}
