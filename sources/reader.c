/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/17 03:43:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			fill_line(int i, char **split_whitespace, t_map **map)
{
	int				k;

	k = -1;
	(*map)->level[i] = (char *)ft_safe_malloc(sizeof(char) * ((*map)->width + 1));
	while (split_whitespace[++k])
	{
		if (ft_strlen(split_whitespace[k]) > 2)
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
	ft_destroy_string_arr(split_whitespace);
	while (split_slash_n[++i])
	{
		split_whitespace = ft_strsplit(split_slash_n[i], ' ');
		if ((*map)->width != ft_len_arr(split_whitespace))
			ft_exit(ERROR_INPUT);
		fill_line(i, split_whitespace, map);
		ft_destroy_string_arr(split_whitespace);
	}
}

static void			check_symbols_illegal(char *file)
{
	int				i;

	i = -1;
	while (file[++i])
	{
		if (ft_isdigit(file[i]) || file[i] == ' ' || file[i] == '\n')
			continue ;
		else
			ft_exit(ERROR_SYMBOLS);
	}
}

// static void			check_field(t_map *map) //здесь буду проверять начало и конец столкбиков, первую и последнюю линию, а также то, что есть хоть один правильный ноль
// {
// 	int				i;

// 	i = -1;
// 	while (file[++i])
// 	{
// 		if (ft_isdigit(file[i]) || file[i] == ' ' || file[i] == '\n')
// 			continue ;
// 		else
// 			ft_exit(ERROR_SYMBOLS);
// 	}
// }

void			read_map(const char *level_name, t_map *map)
{
	char			*file;
	char			**split_slash_n;

	if (!(file = read_big_file(file, (char *)level_name)))
		ft_exit(ERROR_INPUT);
	check_symbols_illegal(file);
	split_slash_n = ft_strsplit(file, '\n');
	ft_strdel(&file);
	if ((map->height = ft_len_arr(split_slash_n)) == 0)
		ft_exit(ERROR_INPUT);
	map->level = (char **)ft_safe_malloc(sizeof(char *) * (map->height + 1));
	map->level[map->height] = NULL;
	fill_map(split_slash_n, &map);
	ft_destroy_string_arr(split_slash_n);
	printf("\naaaa\n");
	print_arr_str(map->level);
	printf("\naaaa\n");
}
