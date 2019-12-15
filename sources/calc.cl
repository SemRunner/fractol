#include "calc.hl"

FR_FLOAT			pow1(FR_FLOAT t, int i)
{
	int		j;
	FR_FLOAT	res;

	res = t;
	j = 0;
	while (++j < i)
		res *= t;
	return (res);
}

FR_FLOAT			fabs1(FR_FLOAT t)
{
	if (t > 0)
		return (t);
	else
		return (-t);
}

t_complex_cl	init_complex_cl(FR_FLOAT re, FR_FLOAT im)
{
	t_complex_cl	res;

	res.re = re;
	res.im = im;
	return (res);
}

int				set_fractol_color(int iter, int max_iter, int type_color)
{
	int		red;
	int		green;
	int		blue;
	FR_FLOAT	t;

	t = (FR_FLOAT)iter / (FR_FLOAT)max_iter;
	red = (int)(9 * (1 - t) * pow1(t, 3) * 255);
	green = (int)(15 * pow1((1 - t), 2) * pow1(t, 2) * 255);
	blue = (int)(8.5 * pow1(1 - t, 3) * t * 255);
	if (type_color == 0)
		return ((red << 16) | (green << 8) | blue);
	else if (type_color == 1)
		return ((red << 16) | (blue << 8) | green);
	else if (type_color == 2)
		return ((blue << 16) | (green << 8) | red);
	else
		return ((blue << 16) | (red << 8) | green);
}

int				cycle_mandel(t_fractol_cl f, t_complex_cl z, t_complex_cl c)
{
	int		iter;

	iter = 0;
	while (pow1(z.re, 2.0) + pow1(z.im, 2.0) <= 4 && ++iter <= f.max_iter)
		z = init_complex_cl(pow1(z.re, 2.0) - pow1(z.im, 2.0) + c.re,
				2.0 * z.re * z.im + c.im);
	return (iter);
}

int				cycle_julia(t_fractol_cl f, t_complex_cl z, t_complex_cl c)
{
	int		iter;

	iter = 0;
	while (pow1(z.re, 2.0) + pow1(z.im, 2.0) <= 4 && ++iter <= f.max_iter)
		z = init_complex_cl(pow1(z.re, 2.0) - pow1(z.im, 2.0) + f.k.re,
			2.0 * z.re * z.im + f.k.im);
	return (iter);
}

int				cycle_brn_sp(t_fractol_cl f, t_complex_cl z, t_complex_cl c)
{
	int		iter;

	iter = 0;
	while (pow1(z.re, 2.0) + pow1(z.im, 2.0) <= 4 && ++iter <= f.max_iter)
		z = init_complex_cl(pow1(z.re, 2.0) - pow1(z.im, 2.0) + c.re,
			2.0 * fabs1(z.re * z.im) + c.im);
	return (iter);
}

int				cycle_cel_man(t_fractol_cl f, t_complex_cl z, t_complex_cl c)
{
	int		iter;

	iter = 0;
	while (pow1(z.re, 2.0) + pow1(z.im, 2.0) <= 4 && ++iter <= f.max_iter)
		z = init_complex_cl(
			fabs1(z.re * z.re - z.im * z.im) + c.re,
			2.0 * z.re * z.im + c.im);
	return (iter);
}

int				cycle_test1(t_fractol_cl f, t_complex_cl z, t_complex_cl c)
{
	int		iter;

	iter = 0;
	while (pow1(z.re, 2.0) + pow1(z.im, 2.0) <= 4 && ++iter <= f.max_iter)
		z = init_complex_cl(
			z.re * z.re - z.im * z.im + c.re,
			-2.0 * z.im * z.re + c.im);
	return (iter);
}

int				cycle_cel_per(t_fractol_cl f, t_complex_cl z, t_complex_cl c)
{
	int		iter;

	iter = 0;
	while (pow1(z.re, 2.0) + pow1(z.im, 2.0) <= 4 && ++iter <= f.max_iter)
		z = init_complex_cl(fabs1(z.re * z.re - z.im * z.im) + c.re,
			-2.0 * fabs1(z.re * z.im + c.im));
	return (iter);
}

int				cycle_spider(t_fractol_cl f, t_complex_cl z, t_complex_cl c)
{
	int		iter;

	iter = 0;
	while (pow1(z.re, 2.0) + pow1(z.im, 2.0) <= 4 && ++iter <= f.max_iter)
	{
		z = init_complex_cl(z.re * z.re - z.im * z.im + c.re,
						2.0 * z.re * z.im + c.im);
		c.re = c.re / 2.0 + z.re;
		c.im = c.im / 2.0 + z.im;
	}	
	return (iter);
}

__kernel void	draw_fractol_cl(__global int *data, t_fractol_cl f)
{
	int			x;
	int			y;
	int			iter;
	t_complex_cl	c;
	t_complex_cl	z;
	size_t		id;

	id = get_global_id(0);
	x = id % f.width;
	y = id / f.width;
	c.im = (y - f.m_y) / f.zoom + f.factor.im;
	c.re = (x - f.m_x) / f.zoom + f.factor.re;
	z = c;
	if (f.type_fractol == FR_MANDEL)
		iter = cycle_mandel(f, z, c);
	else if (f.type_fractol == FR_JULIA)
		iter = cycle_julia(f, z, c);
	else if (f.type_fractol == FR_BRN_SP)
		iter = cycle_brn_sp(f, z, c);
	else if (f.type_fractol == FR_CEL_MAN)
		iter = cycle_cel_man(f, z, c);
	else if (f.type_fractol == FR_TEST1)
		iter = cycle_test1(f, z, c);
	else if (f.type_fractol == FR_CEL_PER)
		iter = cycle_cel_per(f, z, c);
	else if (f.type_fractol == FR_SPIDER)
		iter = cycle_spider(f, z, c);
	((__global int *)data)[id] = set_fractol_color(iter, f.max_iter, f.type_color);
}
