/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectostr_bighex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:57:17 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <prf_spectostr_funcs.h>

char	*spectostr_bighex(t_specifications_def spec, va_list argptr)
{
	char	*output;
	char	tmp[130];
	int		len;
	int		zero_count;

	ft_getunbr_base(get_udec_item_by_size(argptr, spec.sizes),
					BIG_HEX_BASE, tmp);
	len = ft_strlen(tmp);
	if (len == 1 && *tmp == '0' && spec.precision == 0)
		return (ft_zerostr());
	output = (char *)malloc(60 + ((spec.precision > len) ?
								spec.precision : len));
	if (!output)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memcpy(output, tmp, len + 1);
	zero_count = spec.precision - len;
	if (spec.precision != NOT_DETERM && zero_count > 0)
	{
		ft_memmove(output + zero_count, output, len + 1);
		ft_strset(output, '0', zero_count);
	}
	return (output);
}
