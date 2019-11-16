/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 09:29:58 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 13:06:49 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// static void			fill_line(int i, char **split_whitespace, t_map *map)
// {
// 	int				k;

// 	k = -1;
// 	map->level[i] = (char *)ft_safe_malloc(sizeof(char) * (map->width + 1));
// 	while (split_whitespace[++k])
// 		map->level[i][k] = (char)ft_atoi(split_whitespace[k]);
// }

// static void			fill_map(char **split_slash_n, t_map *map)
// {
// 	int				i;
// 	char			**split_whitespace;

// 	i = 0;
// 	split_whitespace = ft_strsplit(split_slash_n[0], ' ');
// 	if (map->width = ft_len_arr(split_whitespace) == 0)
// 		ft_exit(ERROR_INPUT);
// 	fill_line(i, split_whitespace, map);
// 	ft_destroy_string_arr(split_whitespace);
// 	while (++i)
// 	{
// 		split_whitespace = ft_strsplit(split_slash_n[i], ' ');
// 		if (map->width != ft_len_arr(split_whitespace))
// 			ft_exit(ERROR_INPUT);
// 		fill_line(i, split_whitespace, map);
// 		ft_destroy_string_arr(split_whitespace);
// 	}
	
// }

// static void			check_symbols(char *file)
// {
// 	int				i;

// 	i = -1;
// 	while (++i)
// 	{
// 		if (ft_isdigit(file[i] || file[i] == ' ' || file[i] == '\n'))
// 			continue ;
// 		else
// 			ft_exit(ERROR_INPUT);
// 	}
// }

// void			read_map(const char *level_name, t_map *map)
// {
// 	char			*file;
// 	char			**split_slash_n;

// 	file = read_big_file(file, level_name);
// 	check_symbols(file);
// 	split_slash_n = ft_strsplit(file, '\n');
// 	ft_strdel(&file);
// 	if (map->height = ft_len_arr(split_slash_n) == 0)
// 		ft_exit(ERROR_INPUT);
// 	map->level = (char **)ft_safe_malloc(sizeof(char *) * (map->height + 1));
// 	map->level[map->height] = NULL;
// 	fill_map(split_slash_n, map);
// }
