/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:22 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/17 15:27:57 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_tex		*tex_init(t_tex *prev, t_tex *next)
{
	t_tex	*tex;

	tex = (t_tex *)ft_safe_malloc(sizeof(t_tex));
	tex->id = 1;
	tex->tex_ptr = NULL;
	tex->next = next;
	tex->prev = prev;
	return (tex);
}

/*
**	Speed range:
**		m_speed 0 -> 1.0
**		r_speed 0 -> 3.0
*/

t_cam		*cam_init(void)
{
	t_cam	*cam;

	cam = (t_cam *)ft_safe_malloc(sizeof(t_cam));
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
	cam->m_speed = 0.1;
	cam->r_speed = 1.3;
	cam->weapon = NULL;
	return (cam);
}

t_ray		*ray_init(void)
{
	t_ray	*ray;

	ray = (t_ray *)ft_safe_malloc(sizeof(t_ray));
	return (ray);
}

t_cast		*cast_init(void)
{
	t_cast	*cast;

	cast = (t_cast *)ft_safe_malloc(sizeof(t_cast));
	cast->ray = ray_init();
	return (cast);
}
