/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:22 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/17 19:42:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex *tex_init(t_tex *prev, t_tex *next)
{
	t_tex *tex;

	if (!(tex = (t_tex *)malloc(sizeof(t_tex))))
		ft_exit(ERROR_MSG);
	tex->id = 1;
	tex->tex_ptr = NULL;
	tex->next = next;
	tex->prev = prev;
	return (tex);
}

t_cam *cam_init(void)
{
	t_cam *cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		ft_exit(ERROR_MSG);
	cam->pos[X] = 1.5;
	cam->pos[Y] = 1.5;
	cam->v_dir[X] = 1.0;
	cam->v_dir[Y] = 0.0;
	cam->v_plane[X] = 0.0;
	cam->v_plane[Y] = 0.6;
	cam->c_v_dir[X] = cam->v_dir[X];
	cam->c_v_dir[Y] = cam->v_dir[Y];
	cam->c_v_plane[X] = cam->v_plane[X];
	cam->c_v_plane[Y] = cam->v_plane[Y];
	cam->view_height = 0;
	cam->depth = 5;
	cam->m_speed = 0.1; // 0 - 1.0
	cam->r_speed = 1.3; // 0 - 3.0
	return (cam);
}

t_map *map_init(void)
{
	t_map *map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		ft_exit(ERROR_MSG);
	map->width = 0;
	map->height = 0;
	map->level = NULL;
	return (map);
}

t_ray *ray_init(void)
{
	t_ray *ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		ft_exit(ERROR_MSG);
	return (ray);
}

t_cast *cast_init(void)
{
	t_cast *cast;

	if (!(cast = (t_cast *)malloc(sizeof(t_cast))))
		ft_exit(ERROR_MSG);
	cast->ray = ray_init();
	return (cast);
}
