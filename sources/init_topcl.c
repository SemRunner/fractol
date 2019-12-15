/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_topcl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:29:51 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 13:29:51 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_opcl.h"

void		init_opcl(t_opcl *opcl)
{
	opcl->dev = NULL;
	opcl->queue = NULL;
	opcl->context = NULL;
	opcl->program = NULL;
	opcl->kernel = NULL;
	opcl->buf = NULL;
	opcl->total_s = 0;
	opcl->local_s = 0;
}
