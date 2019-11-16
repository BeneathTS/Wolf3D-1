/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 13:45:28 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		get_map_size(const char *level_name, t_map *map)
{
	int			fd;
	char		*buf;
	int			width;
	int			status;

	if ((fd = open(level_name, O_RDONLY)) == -1)
		ft_exit(ERROR_MSG);
	while ((status = get_next_line(fd, &buf)) > 0)
	{
		width = 0;
		++map->height;
		while (buf[width])
			width++;
		if (map->width != width)
			map->width = width;
		// if ((width != map->width && map->width != 0) || width == 0)
		// 	ft_exit(ERROR_MSG);
		// else if (map->width != width)
		// 	map->width = width;
		free(buf);
	}
	free(buf);
	if (status == -1)
		ft_exit(ERROR_MSG);
	close(fd);
}

static void		init_level_buf(t_map *map)
{
	if (map->level)
		free(map->level);
	if (!(map->level = (char**)malloc(sizeof(char*) * (map->height + 1))))
		ft_exit(ERROR_MSG);
	map->level[map->height] = NULL;
}

static void		get_map_data(const char *level_name, t_map *map)
{
	int			fd;
	int			ct;
	int			status;
	char		*buf;

	if ((fd = open(level_name, O_RDONLY)) == -1)
		ft_exit(ERROR_MSG);
	ct = -1;
	while ((status = get_next_line(fd, &buf)) > 0)
	{
		map->level[++ct] = ft_strdup(buf);
		free(buf);
	}
	free(buf);
	if (status == -1)
		ft_exit(ERROR_MSG);
	close(fd);
}

void			read_map(const char *level_name, t_map *map)
{
	get_map_size(level_name, map);
	init_level_buf(map);
	get_map_data(level_name, map);
}
/*
static void			fill_line(int i, char **split_whitespace, t_map *map)
{
	int				k;

	k = -1;
	map->level[i] = (char *)ft_safe_malloc(sizeof(char) * (map->width + 1));
	while (split_whitespace[++k])
		map->level[i][k] = (char)ft_atoi(split_whitespace[k]);
	map->level[i][k] = '\0';
}

static void			fill_map(char **split_slash_n, t_map *map)
{
	int				i;
	char			**split_whitespace;

	i = 0;
	split_whitespace = ft_strsplit(split_slash_n[0], ' ');
	if ((map->width = ft_len_arr(split_whitespace)) == 0)
		ft_exit(ERROR_INPUT);
	fill_line(i, split_whitespace, map);
	ft_destroy_string_arr(split_whitespace);
	while (split_slash_n[++i])
	{
		split_whitespace = ft_strsplit(split_slash_n[i], ' ');
		if (map->width != ft_len_arr(split_whitespace))
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
	fill_map(split_slash_n, map);
	ft_destroy_string_arr(split_slash_n);
}
*/