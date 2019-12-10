/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 13:31:34 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/10 08:58:51 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char				*read_file(int size, char *name)
{
	int				fd;
	int				i;
	char			*str;

	i = -1;
	if (size <= 0 || !name)
		return (NULL);
	if (!(str = ft_strnew(size)))
		return (NULL);
	while (++i < size)
		str[i] = '\0';
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_strdel(&str);
		return (NULL);
	}
	if ((read(fd, str, 0)) < 0)
		return (NULL);
	read(fd, str, size);
	close(fd);
	return (str);
}
