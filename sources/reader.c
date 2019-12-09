/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/10 01:54:00 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static bool			check_borders(t_map *map)
{
	int				i;

	if (!ft_find_symb_in_str_arr(map->level, '0'))
		return (false);
	if (ft_strchr(map->level[0], '0')
		|| ft_strchr(map->level[map->height - 1], '0'))
		return (false);
	i = 0;
	while (++i < map->height - 1)
	{
		if (map->level[i][0] == '0' || map->level[i][map->width - 1] == '0')
			return (false);
	}
	return (true);
}

static bool			check_symbols_in_map(t_map *map)
{
	int				i;
	int				k;

	i = -1;
	while (map->level[++i])
	{
		k = -1;
		if (ft_strlen(map->level[i]) != map->width)
			return (false);
		while (map->level[i][++k])
		{
			if ((((int)map->level[i][k] >= T_11 &&
				(int)map->level[i][k] <= T_38)) || (int)map->level[i][k] == 48)
				continue ;
			else
				return (false);
		}
	}
	return (true);
}

static void			fill_line(int i, char **split_whitespace, t_map **map)
{
	int				k;

	k = -1;
	(*map)->level[i] = (char *)ft_safe_malloc(sizeof(char)
		* (ft_len_arr(split_whitespace) + 1));
	while (split_whitespace[++k])
		(*map)->level[i][k] = split_whitespace[k][0];
	(*map)->level[i][k] = '\0';
}

static void			fill_map(char **split_slash_n,
						char **split_whitespace, t_map **map)
{
	int				i;

	i = -1;
	while (split_slash_n[++i])
	{
		split_whitespace = ft_strsplit(split_slash_n[i], ' ');
		fill_line(i, split_whitespace, map);
		ft_destroy_string_arr(split_whitespace);
	}
}

bool				read_map(const char *level_name, t_map *map)
{
	char			*file;
	char			**split_whitespace;
	char			**split_slash_n;

	if (!(file = read_big_file(file, (char *)level_name)))
		return (false);
	split_slash_n = ft_strsplit(file, '\n');
	ft_strdel(&file);
	if ((map->height = ft_len_arr(split_slash_n)) < 3)
		return (ft_free(split_slash_n, NULL));
	map->level = (char **)ft_safe_malloc(sizeof(char *) * (map->height + 1));
	map->level[map->height] = NULL;
	fill_map(split_slash_n, split_whitespace, &map);
	ft_destroy_string_arr(split_slash_n);
	if ((map->width = ft_strlen(map->level[0])) < 3)
		return (ft_free(map->level, NULL));
	// if (!(check_symbols_in_map(map)))
	// 	return (ft_free(map->level, NULL));
	// if (!check_borders(map))
	// 	return (ft_free(map->level, NULL));
	return (true);
}
