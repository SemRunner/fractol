#ifndef FRACTOL_H
# define FRACTOL_H

# include "fdf.h"
# include "mlx.h"
# include "math.h"
# include "libft.h"

# define HEIGHT 1000
# define WIDTH 1000

# define FR_MANDEL 0
# define FR_JULIA 1

typedef struct	s_complex
{
	long double	re;
	long double	im;
}				t_complex;

typedef struct	s_fractol
{
	t_mlx		*m;

	int			type_fractol;

	int			mouse_x;
	int			mouse_y;

	double		coef_zoom;
	int			max_iter;
	t_complex	centre;
	t_complex	max;
	t_complex	min;
	t_complex	c;
	t_complex	k;
	t_complex	factor;
}				t_fractol;

t_complex		init_complex(double re, double im);

void			fractol_init(t_fractol *f);

/*
** mandelbrot
*/

void			draw_fractol(t_fractol *f);
void			mandelbrot(t_mlx *m, t_complex max, t_complex min, int max_iter);
void			julia(t_mlx *m, t_complex max, t_complex min, int max_iter, t_complex k);

int				fract_keyhook(int keycode, void *fr);
#endif
