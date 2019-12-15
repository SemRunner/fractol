/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl_load_src.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 13:18:37 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/12/15 15:26:56 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractol_opcl.h"

static void	join_to_src(char **src, const char *buf)
{
	char	*tmp;

	tmp = *src;
	*src = ft_strjoin(tmp, buf);
	ft_memdel((void**)&tmp);
}

char		*load_src(char *path)
{
	int		fd;
	char	buf[100];
	int		res;
	char	*src;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	errno = 0;
	src = NULL;
	while ((res = read(fd, buf, 99)) > 0)
	{
		buf[res] = '\0';
		if (!src)
			src = ft_strdup(buf);
		else
			join_to_src(&src, buf);
		buf[0] = '\0';
	}
	close(fd);
	if (errno == ENOMEM)
		ft_memdel((void**)&src);
	return (src);
}
