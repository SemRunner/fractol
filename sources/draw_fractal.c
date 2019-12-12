#include "fractol.h"

int		set_fractol_color(int iter, int max_iter)
{
	int		red;
	int		green;
	int		blue;
	double	t;

	t = (double)iter / (double)max_iter;
	red = (int)(9 * (1 - t) * pow(t, 3) * 255);
	green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	blue = (int)(8.5 * pow(1 - t, 3) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

int			iterate_fractol_point(t_fractol *f)
{
	t_complex	z;
	int			iter;

	z = f->c;
	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iter < f->max_iter)
	{
		if (f->type_fractol == FR_MANDEL)
			z = init_complex(
					pow(z.re, 2.0) - pow(z.im, 2.0) + f->c.re,
					2.0 * z.re * z.im + f->c.im);
		else if (f->type_fractol == FR_JULIA)
			z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + f->k.re,
				2.0 * z.re * z.im + f->k.im);
		iter++;
	}
	return (iter);
}

void		draw_fractol(t_fractol *f)
{
	int			x;
	int			y;
	int			iter;

	f->factor = init_complex((f->max.re - f->min.re) / (f->m->width - 1),
								(f->max.im - f->min.im) / (f->m->height - 1));
	y = -1;
	while (++y < HEIGHT)
	{
		f->c.im = f->max.im - y * f->factor.im;
		x = -1;
		while (++x < WIDTH)
		{
			f->c.re = f->min.re + x * f->factor.re;
			iter = iterate_fractol_point(f);
			putpixel(
				f->m,
				x, y,
				set_fractol_color(iter, f->max_iter));
		}
	}
	draw_main_image(f->m);
}
