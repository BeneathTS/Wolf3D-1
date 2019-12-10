/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:36:31 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/10 04:51:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map		*map_init(char *name)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		ft_exit(ERROR_MSG);
	map->name = ft_strdup(name);
	map->width = 0;
	map->height = 0;
	map->level = NULL;
	map->next = NULL;
	return (map);
}

t_map		*find_current_map(const char *name, t_map **map)
{
	t_map	*tmp;
	t_map	*new_node;

	if (!(*map))
		return (*map = map_init((char *)name));
	tmp = *map;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	new_node = map_init((char *)name);
	tmp->next = new_node;
	return (new_node);
}

void		delete_list_maps(t_map **map)
{
	t_map	*tmp;

	while (*map)
	{
		tmp = *map;
		*map = (*map)->next;
		ft_strdel(&tmp->name);
		ft_destroy_string_arr(tmp->level);
		free(tmp);
	}
}
