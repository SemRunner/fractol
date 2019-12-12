#include "fractol.h"

void	fractol_init(t_fractol *f)
{
	f->m = NULL;
	f->max_iter = 10;
	f->max = init_complex(2.0, 2.0);
	f->min = init_complex(-2.0, -2.0);
	f->k = init_complex(0.0, 0.0);
	f->type_fractol = FR_MANDEL;
	f->coef_zoom = 1.0;
	f->centre = init_complex(0.0, 0.0);
}
