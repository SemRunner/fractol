/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:49:54 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 19:58:00 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

void	clear_image(t_mlx *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
			putpixel(m, j, i, 0);
	}
}
