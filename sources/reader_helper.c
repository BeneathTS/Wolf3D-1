/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:21:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/15 06:22:04 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

bool			reader_error(t_map **map)
{
	int			i;

	i = 0;
	while ((*map)->level[i])
	{
		ft_strdel(&(*map)->level[i]);
		i++;
	}
	free((*map)->level);
	(*map)->level = NULL;
	return (false);
}

size_t			ft_strlen_without_symb(char symb, const char *s)
{
	size_t		i;
	size_t		count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != symb)
			count++;
	}
	return (count);
}

char			*ft_strnew_without_symb(char symb, char *str)
{
	int			i;
	int			k;
	int			len;
	char		*new_str;

	len = ft_strlen_without_symb(' ', (const char *)str);
	new_str = ft_strnew(len);
	i = -1;
	k = -1;
	while (str[++i])
	{
		if (str[i] != symb)
			new_str[++k] = str[i];
	}
	return (new_str);
}

char			*read_file(t_map *map)
{
	char		*str1;
	char		*str2;
	int			fd;
	int			res;

	if ((fd = open(map->name, O_RDONLY)) < 0)
		return (NULL);
	if (get_next_line(fd, &str2) == -1)
		return (NULL);
	map->width = ft_strlen_without_symb(' ', str2);
	while ((res = get_next_line(fd, &str1)) > 0)
		str2 = ft_strjoin_free(str2, str1, 3);
	ft_strdel(&str1);
	if (res == -1)
	{
		ft_strdel(&str2);
		return (NULL);
	}
	close(fd);
	return (str2);
}
