/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/10 06:33:46 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_strlen_a(char symb, const char *s)
{
	size_t	i;
	size_t	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != symb)
			count++;
	}
	return (count);
}


char			*read_file(t_map *map)
{
	char 		*str1;
	char 		*str2;
	int			fd;
	int			res;

	if ((fd = open(map->name, O_RDONLY)) < 0)
		return (NULL);
	if (get_next_line(fd, &str2) == -1)
		return (NULL);
	map->width = ft_strlen_a(' ', str2);
	while((res = get_next_line(fd, &str1)) > 0)
		str2 = ft_strjoin_free(str2, str1, 2);
	if (res == -1)
	{
		ft_strdel(&str2);
		return (NULL);
	}
	close(fd);
	return (str2);
}

static void		count_height(char *file, t_map *map)
{
	int			i;
	int			file_len;

	i = map->width;
	file_len = ft_strlen_a(' ', file);
	while (i <= file_len)
	{
		i += map->width;
		map->height++;
	}
}

static void			fill_map(char *file, t_map **map)
{
	int				i;
	int				k;
	int				j;
	
	i = -1;
	k = 0;
	//	Что тут должно происходить?
	// 	Выделил место под лвл
	// 	Дальше заполняю линию не пробелами
	// 	Меммуваю file или играюсь с счетчиками
	(*map)->level = (char **)ft_memalloc(sizeof(char *) * ((*map)->height + 1)); //mb problem
	while (++i < (*map)->height)
	{
		(*map)->level[i] = ft_strnew((*map)->width);
		while (k < (*map)->width)
		{
			(*map)->level[i]
		}
		// (*map)->level[i] = ft_strsub(file, k, (*map)->width);
		k += (*map)->width;
	}
}

bool			read_map(const char *level_name, t_map *map)
{
	char		*file;

	if (!(file = read_file(map)))
		return (false);
	count_height(file, map);
	if (map->height < 3 || map->width < 3)
	{
		ft_strdel(&file);
		return (false);
	}
	fill_map(file, &map);
	return (true);
}
