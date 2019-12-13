#include "fractol.h"

void	zoom_fractol(t_fractol *f, int keycode)
{
	if (keycode == FDF_KEY_UP || keycode == FDF_SCROLL_D)
	{
		f->zoom *= 1.2;
		f->factor.re -= (f->m_x - f->mouse_x) * 1.2 / f->zoom;
		f->factor.im -= (f->m_y - f->mouse_y) * 1.2 / f->zoom;
		f->m_x = f->mouse_x;
		f->m_y = f->mouse_y;
	}
	else if (keycode == FDF_KEY_DOWN || keycode == FDF_SCROLL_U)
	{
		f->zoom /= 1.2;
		f->factor.re -= (f->m_x - f->mouse_x) / 1.2 / f->zoom;
		f->factor.im -= (f->m_y - f->mouse_y) / 1.2 / f->zoom;
		f->m_x = f->mouse_x;
		f->m_y = f->mouse_y;
	}
}

int		set_fractol_color(int iter, int max_iter, int type_color)
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

int			iterate_fractol_point(t_fractol *f)
{
	t_complex	z;
	int			iter;

	z = f->c;
	iter = 0;
	if (f->type_fractol == FR_MANDEL)
		while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
			z = init_complex(
					pow(z.re, 2.0) - pow(z.im, 2.0) + f->c.re,
					2.0 * z.re * z.im + f->c.im);
	else if (f->type_fractol == FR_JULIA)
		while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
			z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + f->k.re,
				2.0 * z.re * z.im + f->k.im);
	else if (f->type_fractol == FR_BRN_SP)
		while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
			z = init_complex(
				pow(z.re, 2.0) - pow(z.im, 2.0) + f->c.re,
				2.0 * fabsl(z.re * z.im) + f->c.im);
	else if (f->type_fractol == FR_CEL_MAN)
		while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
			z = init_complex(
				fabsl(z.re * z.re - z.im * z.im) + f->c.re,
				2.0 * z.re * z.im + f->c.im);
	else if (f->type_fractol == FR_TEST1)
		while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
			z = init_complex(
				z.re * z.re - z.im * z.im + f->c.re,
				-2.0 * z.im * z.re + f->c.im);
	else if (f->type_fractol == FR_CEL_PER)
		while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
			z = init_complex(
				fabsl(z.re * z.re - z.im * z.im) + f->c.re,
				-2.0 * fabsl(z.re * z.im + f->c.im));
	return (iter);
}

void		put_fractol_legend(t_fractol *f)
{
	char str[50];

	str[0] = '\0';
	mlx_string_put(f->m->ptr, f->m->win, 10, 10, FDF_WHITE, "FRACT'OL CURRENT CONDITIONS:");
	ft_printf("%yTYPE OF FRACTOL: ", str);
	if (f->type_fractol == 0)
		ft_printf("%yMANDEL", str);
	else if (f->type_fractol == 1)
		ft_printf("%yJULIA", str);
	else if (f->type_fractol == 2)
		ft_printf("%yBURNING SHIP", str);
	else if (f->type_fractol == 3)
		ft_printf("%yCEL_MAN", str);
	else if (f->type_fractol == 4)
		ft_printf("%yTEST", str);
	else if (f->type_fractol == 5)
		ft_printf("%yCEL_PER", str);	
	mlx_string_put(f->m->ptr, f->m->win, 10, 30, FDF_LGREEN, str);
	str[0] = '\0';
	ft_printf("%yITERATIONS: %d", str, f->max_iter);
	mlx_string_put(f->m->ptr, f->m->win, 10, 50, FDF_LGREEN, str);

	mlx_string_put(f->m->ptr, f->m->win, 10, 80, FDF_GRAY, "KEYS BINDINGS:");
	mlx_string_put(f->m->ptr, f->m->win, 10, 100, FDF_GRAY, "UP/DOWN, SCROLLS: zoom");
	mlx_string_put(f->m->ptr, f->m->win, 10, 120, FDF_GRAY, "LEFT BUT: move fractal");
	mlx_string_put(f->m->ptr, f->m->win, 10, 140, FDF_GRAY, "+/-: count iterations");
	mlx_string_put(f->m->ptr, f->m->win, 10, 160, FDF_GRAY, "numbers, X: change type fractal");
	mlx_string_put(f->m->ptr, f->m->win, 10, 180, FDF_GRAY, "C: change color");
	mlx_string_put(f->m->ptr, f->m->win, 10, 200, FDF_GRAY, "Z: reset fractal");
	mlx_string_put(f->m->ptr, f->m->win, 10, 220, FDF_GRAY, "ESC, Q: exit");
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
