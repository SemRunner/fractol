/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 19:41:40 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/13 19:41:41 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractol *f)
{
	f->m = NULL;
	f->max_iter = 10;
	f->max = init_complex(2.0, 2.0);
	f->min = init_complex(-2.0, -2.0);
	f->k = init_complex(0.0, 0.0);
	f->type_fractol = FR_MANDEL;
	f->type_color = 0;
	f->centre = init_complex(0.0, 0.0);
	f->zoom = 150.0;
	f->in_move = 0;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->m_xx = 0;
	f->m_yy = 0;
	f->m_x = WIDTH / 2;
	f->m_y = HEIGHT / 2;
	f->factor = init_complex((f->max.re - f->min.re) / (WIDTH - 1),
								(f->max.im - f->min.im) / (HEIGHT - 1));
	f->type_device = 1;
}

void	fractol_reset(t_fractol *f)
{
	f->max_iter = 10;
	f->max = init_complex(2.0, 2.0);
	f->min = init_complex(-2.0, -2.0);
	f->k = init_complex(0.0, 0.0);
	f->zoom = 150;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->m_x = WIDTH / 2;
	f->m_y = HEIGHT / 2;
	f->m_xx = 0;
	f->m_yy = 0;
	f->factor = init_complex((f->max.re - f->min.re) / (WIDTH - 1),
								(f->max.im - f->min.im) / (HEIGHT - 1));
}
