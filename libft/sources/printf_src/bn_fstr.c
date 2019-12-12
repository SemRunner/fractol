/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bn_fstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 18:43:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <prf_double.h>

static void		ft_putn_output(long long n, char *output)
{
	char	s[2];

	if (n > 0)
	{
		ft_putn_output(n / 10, output);
		s[0] = n % 10 + '0';
		s[1] = '\0';
		ft_strcat(output, s);
	}
}

void			ft_putnbr_output(long int n, char *output)
{
	long long nb;

	nb = n;
	if (nb == 0)
	{
		ft_strcat(output, "0");
		return ;
	}
	else if (nb < 0)
	{
		ft_strcat(output, "-");
		nb = -nb;
	}
	ft_putn_output(nb, output);
}

void			ft_strcatnbr(char *output, long int nbr)
{
	char tmp_str[30];

	tmp_str[0] = '\0';
	ft_putnbr_output(nbr, tmp_str);
	ft_strcat(output, tmp_str);
}

void			putnzeros(char *output, int prec)
{
	while (prec-- > 0)
	{
		ft_strcat(output, "0");
	}
}

void			ft_strcatnbr_wzeros(char *output, long long nbr, int len)
{
	char tmp[20];

	tmp[0] = 0;
	if (nbr < 0)
		ft_strcat(output, "-");
	ft_strcatnbr(tmp, ABS(nbr));
	while (len-- > (int)ft_strlen(tmp))
		ft_strcat(output, "0");
	ft_strcat(output, tmp);
}
