/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_fractol2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:27:02 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 19:28:53 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				cycle_cel_per(t_fractol *f, t_complex z)
{
	int		iter;

	iter = 0;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
		z = init_complex(fabsl(z.re * z.re - z.im * z.im) + f->c.re,
			-2.0 * fabsl(z.re * z.im + f->c.im));
	return (iter);
}

int				cycle_spider(t_fractol *f, t_complex z)
{
	int		iter;
	t_complex	c_tmp;

	iter = 0;
	c_tmp = f->c;
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && ++iter <= f->max_iter)
	{
		z = init_complex(z.re * z.re - z.im * z.im + c_tmp.re,
						2.0 * z.re * z.im + c_tmp.im);
		c_tmp.re = c_tmp.re / 2.0 + z.re;
		c_tmp.im = c_tmp.im / 2.0 + z.im;
	}	
	return (iter);
}
