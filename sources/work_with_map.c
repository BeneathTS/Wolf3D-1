/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 03:36:31 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/15 04:59:02 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map			*map_init(char *name)
{
	t_map		*map;

	map = (t_map *)ft_safe_malloc(sizeof(t_map));
	map->name = ft_strdup(name);
	map->width = 0;
	map->height = 0;
	map->level = NULL;
	map->next = NULL;
	return (map);
}

static t_map	*find_prev_map(t_map *current_map, t_map **map)
{
	t_map		*tmp;

	tmp = *map;
	while (tmp && tmp->next)
	{
		if (tmp->next == current_map)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_map			*find_current_map(const char *name, t_map **map)
{
	t_map		*tmp;
	t_map		*node;

	if (!(*map))
		return (*map = map_init((char *)name));
	tmp = *map;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->name) == 0)
		{
			if (!(node = find_prev_map(tmp, map)))
				return (tmp);
			node->next = tmp->next;
			tmp->next = *map;
			*map = tmp;
			return (tmp);
		}
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	node = map_init((char *)name);
	node->next = *map;
	*map = node;
	return (node);
}

void			delete_list_maps(t_map **map)
{
	t_map		*tmp;

	while (*map)
	{
		tmp = *map;
		*map = (*map)->next;
		ft_strdel(&tmp->name);
		ft_destroy_string_arr(tmp->level);
		free(tmp);
	}
}
