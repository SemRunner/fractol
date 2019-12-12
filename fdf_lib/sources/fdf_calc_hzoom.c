/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calc_hzoom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:52:52 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 23:46:20 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static void		change_m_params(t_mlx *m, int coef)
{
	if (coef > 0)
	{
		m->zoom_coef++;
		m->h_coef++;
		m->camera_x = (int)(1.5 * (double)m->camera_x);
		m->camera_y = (int)(1.5 * (double)m->camera_y);
	}
	else if (coef < 0)
	{
		m->zoom_coef--;
		m->h_coef--;
		m->camera_x = (int)(0.6666667 * (double)m->camera_x);
		m->camera_y = (int)(0.6666667 * (double)m->camera_y);
	}
}

void			calc_hzoom(t_mlx *m, int coef)
{
	int		i;

	change_m_params(m, coef);
	m->zoom = 1.0;
	m->h = 1.0;
	i = m->zoom_coef;
	if (i == 20)
		m->zoom = 1.0;
	else if (i < 20)
		while (i++ < 20)
			m->zoom *= 0.6666667;
	else if (i > 20)
		while (i-- > 20)
			m->zoom *= 1.5;
	i = m->h_coef;
	if (i == 40)
		m->h = 1.0;
	else if (i < 40)
		while (i++ < 40)
			m->h *= 0.6666667;
	else if (i > 40)
		while (i-- > 40)
			m->h *= 1.5;
}
