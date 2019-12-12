/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_outstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:08:25 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

#include "ft_outbuff.h"
#include "ft_outbuff_dst.h"

char	*change_outstr(t_specifications_def spec, va_list argptr)
{
	if (spec.spec == 16)
	{
		ft_force_buff();
		ft_set_g_outstr(va_arg(argptr, char*));
	}
	return (ft_zerostr());
}
