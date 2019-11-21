/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:54 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/21 13:18:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define RAY cast->ray

/*
** The function in which we calculate the initial values.
**
** Function struct:
** 1. Set wall_hit to "no" because we have not found the wall yet.
** 2. Set the initial position of the ray.
** 3. Find y of first intersection point.
** 4. Find x of first intersection point.
** 5. Find the x step value.
** 6. Find the y step value.
** 7. Find the distance between two intersection points along x.
**		(horizontal intersections)
** 8. Find the distance between two intersection points along y.
**		(vertical intersections)
**
** little description:
** Find the step for the direction of the ray. (like bresenhem algorithm)
*/

static void		set_values(t_cast *cast, t_cam *cam, int *wall_hit)
{
	*wall_hit = No;
	cast->distance = 0;
	RAY->m_pos[X] = (int)cam->pos[X];
	RAY->m_pos[Y] = (int)cam->pos[Y];
	RAY->d_dist[H] = sqrt(pow(RAY->v_dir[Y], 2.0) /
		pow(RAY->v_dir[X], 2.0) + 1);
	RAY->d_dist[V] = sqrt(pow(RAY->v_dir[X], 2.0) /
		pow(RAY->v_dir[Y], 2.0) + 1);
	cast->step[X] = (RAY->v_dir[X] < 0 ? -1 : 1);
	cast->step[Y] = (RAY->v_dir[Y] < 0 ? -1 : 1);
	RAY->s_dist[H] = (cast->step[X] > 0
		? RAY->m_pos[X] - cam->pos[X] + 1
		: cam->pos[X] - RAY->m_pos[X]) * RAY->d_dist[H];
	RAY->s_dist[V] = (cast->step[Y] > 0
		? RAY->m_pos[Y] - cam->pos[Y] + 1
		: cam->pos[Y] - RAY->m_pos[Y]) * RAY->d_dist[V];
}

/*
** The raycasting function.
**
** Function struct:
** 1. Find the wall:
**   1.1 Take a step for the shortest direction until a wall is found.
**   1.2 Remember the type of intersection for the last step.
**		(horizontal / vertical)
*/

static void		wall_search(t_cast *cast, t_env *env, int *wall_hit)
{
	while (*wall_hit == No)
	{
		if (RAY->s_dist[H] < RAY->s_dist[V])
		{
			RAY->s_dist[H] += RAY->d_dist[H];
			RAY->m_pos[X] += cast->step[X];
			RAY->side = H;
		}
		else
		{
			RAY->s_dist[V] += RAY->d_dist[V];
			RAY->m_pos[Y] += cast->step[Y];
			RAY->side = V;
		}
		if (env->map->level[env->RAY->m_pos[Y]][env->RAY->m_pos[X]] > '0')
			*wall_hit = Yes;
	}
}

/*
** Body of raycasting function.
**
** Function struct:
** 1. Set initial value to variables.
** 2. Cast a ray until it meets a wall.
** 3. Calculate distance to the wall and wall height.
*/

void			cast_a_ray(t_cast *cast, t_cam *cam, t_env *env)
{
	int			wall_hit;

	set_values(cast, cam, &wall_hit);
	wall_search(cast, env, &wall_hit);
	if (wall_hit == Yes)
	{
		cast->distance = (RAY->side == H
			? (RAY->m_pos[X] - cam->pos[X]
				+ (1 - cast->step[X]) / 2) / RAY->v_dir[X]
			: (RAY->m_pos[Y] - cam->pos[Y] +
				(1 - cast->step[Y]) / 2) / RAY->v_dir[Y]);
		cast->wall_height = (int)floor(HEIGHT * 1.27 / cast->distance);
	}
}
