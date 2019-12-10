/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/10 08:02:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
	char 		*str1;
	char 		*str2;
	int			fd;
	int			res;

	if ((fd = open(map->name, O_RDONLY)) < 0)
		return (NULL);
	if (get_next_line(fd, &str2) == -1)
		return (NULL);
	map->width = ft_strlen_without_symb(' ', str2);
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
	file_len = ft_strlen_without_symb(' ', file);
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
	char			*file_without_whitespace;
	
	i = -1;
	k = 0;
	file_without_whitespace = ft_strnew_without_symb(' ', file);
	(*map)->level =
		(char **)ft_memalloc(sizeof(char *) * ((*map)->height + 1));
	while (++i < (*map)->height)
	{
		(*map)->level[i] =
			ft_strsub(file_without_whitespace, k, (*map)->width);
		k += (*map)->width;
	}
	ft_strdel(&file_without_whitespace);
}
//прикрутить проверки
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
	ft_strdel(&file);
	return (true);
}
