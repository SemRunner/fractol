/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:49:54 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/30 16:31:41 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void		putpixel(t_mlx *m, int x, int y, int color)
{
	if ((0 <= x && x < m->width) && (0 <= y && y < m->height))
		m->data_mainim[y * (m->size_line / sizeof(int)) + x] = color;
}

static void	init_dxy_xy(t_point *dxy, t_point *xy, t_point start,
							t_point end)
{
	dxy->x = end.x - start.x;
	dxy->y = end.y - start.y;
	xy->x = start.x;
	xy->y = start.y;
}

static void	putline_low(t_mlx *m, t_point start, t_point end, int not_black)
{
	t_point	dxy;
	t_point	xy;
	int		yi;
	int		d;

	init_dxy_xy(&dxy, &xy, start, end);
	yi = 1;
	if (dxy.y < 0)
	{
		yi = -1;
		dxy.y = -dxy.y;
	}
	d = 2 * dxy.y - dxy.x;
	while (xy.x <= end.x)
	{
		(not_black == 0x0) ? putpixel(m, xy.x, xy.y, not_black) : putpixel(m,
			xy.x, xy.y, color_gradient(start, end, perc(start.x, end.x, xy.x)));
		if (d > 0)
		{
			xy.y = xy.y + yi;
			d = d - 2 * dxy.x;
		}
		d = d + 2 * dxy.y;
		xy.x++;
	}
}

static void	putline_high(t_mlx *m, t_point start, t_point end, int not_black)
{
	t_point	dxy;
	t_point	xy;
	int		xi;
	int		d;

	init_dxy_xy(&dxy, &xy, start, end);
	xi = 1;
	if (dxy.x < 0)
	{
		xi = -1;
		dxy.x = -dxy.x;
	}
	d = 2 * dxy.x - dxy.y;
	while (xy.y <= end.y)
	{
		(not_black == 0x0) ? putpixel(m, xy.x, xy.y, not_black) : putpixel(m,
			xy.x, xy.y, color_gradient(start, end, perc(start.y, end.y, xy.y)));
		if (d > 0)
		{
			xy.x = xy.x + xi;
			d = d - 2 * dxy.y;
		}
		d = d + 2 * dxy.x;
		xy.y++;
	}
}

void		putline(t_mlx *m, t_point start, t_point end, int not_black)
{
	if (ABS(end.y - start.y) < ABS(end.x - start.x))
	{
		if (start.x > end.x)
			putline_low(m, end, start, not_black);
		else
			putline_low(m, start, end, not_black);
	}
	else
	{
		if (start.y > end.y)
			putline_high(m, end, start, not_black);
		else
			putline_high(m, start, end, not_black);
	}
}
