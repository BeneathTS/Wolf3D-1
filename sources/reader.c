/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/18 04:22:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			check_symbols_illegal(char *file)
{
	int				i;

	i = -1;
	while (file[++i])
	{
		if (((int)file[i] >= T_1 && (int)file[i] <= T_37))
			continue ;
		else
			ft_exit(ERROR_SYMBOLS);
	}
}

static void			fill_line(int i, char **split_whitespace, t_map **map)
{
	int				k;

	k = -1;
	(*map)->level[i] = (char *)ft_safe_malloc(sizeof(char)
		* ((*map)->width + 1));
	while (split_whitespace[++k])
	{
		if (ft_strlen(split_whitespace[k]) >= 2)
			ft_exit(ERROR_INPUT);
		(*map)->level[i][k] = *(split_whitespace[k]);
	}
	(*map)->level[i][k] = '\0';
}

static void			fill_map(char **split_slash_n, t_map **map)
{
	int				i;
	char			**split_whitespace;

	i = 0;
	split_whitespace = ft_strsplit(split_slash_n[0], ' ');
	if (((*map)->width = ft_len_arr(split_whitespace)) == 0)
		ft_exit(ERROR_INPUT);
	fill_line(i, split_whitespace, map);
	check_symbols_illegal((*map)->level[i]);
	ft_destroy_string_arr(split_whitespace);
	while (split_slash_n[++i])
	{
		split_whitespace = ft_strsplit(split_slash_n[i], ' ');
		if ((*map)->width != ft_len_arr(split_whitespace))
			ft_exit(ERROR_INPUT);
		fill_line(i, split_whitespace, map);
		check_symbols_illegal((*map)->level[i]);
		ft_destroy_string_arr(split_whitespace);
	}
}

static void			check_boundaries_map(t_map *map)
{
	int				i;

	if (!ft_find_symb_in_str_arr(map->level, '0'))
		ft_exit(ERROR_INPUT);
	if (ft_strchr(map->level[0], '0')
		|| ft_strchr(map->level[map->height - 1], '0'))
		ft_exit(ERROR_INPUT);
	i = 0;
	while (++i < map->height - 1)
	{
		if (map->level[i][0] == '0' || map->level[i][map->width - 1] == '0')
			ft_exit(ERROR_SYMBOLS);
	}
}

void				read_map(const char *level_name, t_map *map)
{
	char			*file;
	char			**split_slash_n;

	if (!(file = read_big_file(file, (char *)level_name)))
		ft_exit(ERROR_INPUT);
	split_slash_n = ft_strsplit(file, '\n');
	ft_strdel(&file);
	if ((map->height = ft_len_arr(split_slash_n)) == 0)
		ft_exit(ERROR_INPUT);
	map->level = (char **)ft_safe_malloc(sizeof(char *) * (map->height + 1));
	map->level[map->height] = NULL;
	fill_map(split_slash_n, &map);
	check_boundaries_map(map);
	ft_destroy_string_arr(split_slash_n);
}
