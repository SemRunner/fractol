/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_figures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:15:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:57:01 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void				putcircle(t_mlx *m, t_point center, int radius,
							int not_black)
{
	int		x;
	int		y;
	int		delta;
	int		error;
	int		color;

	color = not_black == 0 ? 0 : center.color;
	x = 0;
	y = radius;
	delta = 1 - 2 * radius;
	error = 0;
	while (y >= 0)
	{
		putpixel(m, center.x + x, center.y + y, color);
		putpixel(m, center.x + x, center.y - y, color);
		putpixel(m, center.x - x, center.y + y, color);
		putpixel(m, center.x - x, center.y - y, color);
		error = 2 * (delta + y) - 1;
		if ((delta < 0) && (error <= 0))
			delta += 2 * (++x) + 1;
		else if ((delta > 0) && error > 0)
			delta -= 2 * (--y) + 1;
		else
			delta += 2 * ((++x) - (y--));
	}
}

void				put_thickcircle(t_mlx *m, t_point center,
								int radius, int not_black)
{
	putcircle(m, center, radius, not_black);
	putcircle(m, center, radius - 1, not_black);
	putcircle(m, center, radius + 1, not_black);
}

void				put_full_thickcircle(t_mlx *m, t_point center,
								int radius, int not_black)
{
	putcircle(m, center, radius, not_black);
	putcircle(m, center, radius - 1, not_black);
	putcircle(m, center, --radius, not_black);
	while (radius)
		putcircle(m, center, --radius, not_black);
}

void				put_thickline(t_mlx *m, t_point start,
								t_point end, int not_black)
{
	int		diffx;
	int		diffy;

	putline(m, start, end, not_black);
	diffx = ABS(start.x - end.x);
	diffy = ABS(start.y - end.y);
	if (diffx < diffy)
	{
		start.x -= 1;
		end.x -= 1;
		putline(m, start, end, not_black);
		start.x += 2;
		end.x += 2;
		putline(m, start, end, not_black);
	}
	else
	{
		start.y -= 1;
		end.y -= 1;
		putline(m, start, end, not_black);
		start.y += 2;
		end.y += 2;
		putline(m, start, end, not_black);
	}
}
