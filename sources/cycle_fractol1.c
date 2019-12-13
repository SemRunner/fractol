/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_fractol1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:12:44 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 19:31:15 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				cycle_mandel(t_fractol *f, t_complex z)
{
	int		iter;

	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + f->c.re,
				2.0 * z.re * z.im + f->c.im);
	return (iter);
}

int				cycle_julia(t_fractol *f, t_complex z)
{
	int		iter;

	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + f->k.re,
			2.0 * z.re * z.im + f->k.im);
	return (iter);
}

int				cycle_brn_sp(t_fractol *f, t_complex z)
{
	int		iter;

	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + f->c.re,
			2.0 * fabsl(z.re * z.im) + f->c.im);
	return (iter);
}

int				cycle_cel_man(t_fractol *f, t_complex z)
{
	int		iter;

	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
		z = init_complex(
			fabsl(z.re * z.re - z.im * z.im) + f->c.re,
			2.0 * z.re * z.im + f->c.im);
	return (iter);
}

int				cycle_test1(t_fractol *f, t_complex z)
{
	int		iter;

	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
		z = init_complex(
			z.re * z.re - z.im * z.im + f->c.re,
			-2.0 * z.im * z.re + f->c.im);
	return (iter);
}