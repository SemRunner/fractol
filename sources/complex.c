#include "fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex res;

	res.re = re;
	res.im = im;
	return (res);
}
