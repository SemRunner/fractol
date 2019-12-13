



int			set_fractol_color(int iter, int max_iter, int type_color)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)iter / (double)max_iter;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow(1 - t, 3) * t * 255);
	if (type_color == 0)
		return ((red << 16) | (green << 8) | blue);
	else if (type_color == 1)
		return ((red << 16) | (blue << 8) | green);
	else if (type_color == 2)
		return ((blue << 16) | (green << 8) | red);
	else
		return ((blue << 16) | (red << 8) | green);
}

void		draw_fractol(t_fractol *f)
{
	int			x;
	int			y;
	int			iter;

	y = -1;
	while (++y < f->m->height)
	{
		f->c.im = (y - f->m_y) / f->zoom + f->factor.im;
		x = -1;
		while (++x < f->m->width)
		{
			f->c.re = (x - f->m_x) / f->zoom + f->factor.re;
			iter = iterate_fractol_point(f);
			putpixel(
				f->m,
				x, y,
				set_fractol_color(iter, f->max_iter, f->type_color));
		}
	}
	mlx_clear_window(f->m->ptr, f->m->win);
	draw_main_image(f->m);
	put_fractol_legend(f);
}