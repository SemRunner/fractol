/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_bak.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:27:02 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_global_bak.h>

#include <libft.h>
#include <prf_arg_mode.h>
#include "ft_outbuff_dst.h"

t_global_bak	global_init(void)
{
	t_global_bak bak;

	bak.fd = ft_get_g_outfd();
	bak.outstr = ft_get_g_outstr();
	bak.arg_mode = get_argmode();
	errno = 0;
	ft_set_g_outfd(1);
	ft_set_g_outstr(NULL);
	init_argmode();
	return (bak);
}

void			global_restore(t_global_bak bak)
{
	ft_set_g_outfd(bak.fd);
	ft_set_g_outstr(bak.outstr);
	set_argmode(bak.arg_mode);
}
