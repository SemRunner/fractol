/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outbuff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrisha <mtrisha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:43:54 by mtrisha           #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OUTBUFF_H
# define FT_OUTBUFF_H

# define PRF_BUFF_SIZE 8196

typedef struct	s_outbuff
{
	char	buff[PRF_BUFF_SIZE];
	int		curlen;
	int		fd;
}				t_outbuff;

void			ft_force_buff(void);
int				ft_buf_add(int fd, const char *str, int len);

#endif
