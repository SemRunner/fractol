#include "fractol.h"

int			fract_keyhook(int keycode, void *fr)
{
	t_fractol *f;

	f = fr;
	ft_printf("%d\n", keycode);
	if (keycode == FDF_KEY_Q || keycode == FDF_KEY_ESC)
		tmlx_destroy(f->m, 0);
	else if (keycode == FDF_KEY_PLUS)
		f->max_iter +=
			(int)((double)(f->max_iter) * 0.2) > 0 ? (int)((double)(f->max_iter)) * 0.2 : 1;
	else if (keycode == FDF_KEY_MINUS && f->max_iter > 2)
		f->max_iter -= 
			(int)((double)(f->max_iter) * 0.2) > 0 ? (int)((double)(f->max_iter)) * 0.2 : 1;
	else if (keycode == 7)
		f->type_fractol = (f->type_fractol + 1) % 2;
	else if (keycode == FDF_KEY_UP)
	{
		f->coef_zoom *= 1.2;
		double	coef_x = (double)f->mouse_x / (double)WIDTH;		//coef_x = 0..1
		double	coef_y = (double)f->mouse_y / (double)HEIGHT;
		f->centre.re += (coef_x - 0.5) * 4.0 / f->coef_zoom;
		f->centre.im += (coef_y - 0.5) * 4.0 / f->coef_zoom;
		f->max.re = (f->max.re - f->centre.re) / f->coef_zoom;
		f->max.im = (f->max.im - f->centre.im) / f->coef_zoom;
		f->min.re = (f->min.re - f->centre.re) / f->coef_zoom;
		f->min.im = (f->min.im - f->centre.im) / f->coef_zoom;
	}
	else if (keycode == FDF_KEY_DOWN)
	{
		f->coef_zoom *= 0.8;
		double	coef_x = (double)f->mouse_x / (double)WIDTH;		//coef_x = 0..1
		double	coef_y = (double)f->mouse_y / (double)HEIGHT;
		f->centre.re += (coef_x - 0.5) * 4.0 / f->coef_zoom;
		f->centre.im += (coef_y - 0.5) * 4.0 / f->coef_zoom;
		f->max.re = (f->max.re - f->centre.re) / f->coef_zoom;
		f->max.im = (f->max.im - f->centre.im) / f->coef_zoom;
		f->min.re = (f->min.re - f->centre.re) / f->coef_zoom;
		f->min.im = (f->min.im - f->centre.im) / f->coef_zoom;
	}
	draw_fractol(f);
	ft_printf("max_iter = %d\n", f->max_iter);
	return (0);
}