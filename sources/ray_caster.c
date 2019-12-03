/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:54 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/03 17:50:24 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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

static void		set_values(t_ray *ray, t_cast *cast, t_cam *cam, int *wall_hit)
{
	*wall_hit = No;
	cast->distance = 0;
	ray->m_pos[X] = (int)cam->pos[X];
	ray->m_pos[Y] = (int)cam->pos[Y];
	ray->d_dist[H] = sqrt(pow(ray->v_dir[Y], 2.0) /
		pow(ray->v_dir[X], 2.0) + 1);
	ray->d_dist[V] = sqrt(pow(ray->v_dir[X], 2.0) /
		pow(ray->v_dir[Y], 2.0) + 1);
	cast->step[X] = (ray->v_dir[X] < 0 ? -1 : 1);
	cast->step[Y] = (ray->v_dir[Y] < 0 ? -1 : 1);
	ray->s_dist[H] = (cast->step[X] > 0
		? ray->m_pos[X] - cam->pos[X] + 1
		: cam->pos[X] - ray->m_pos[X]) * ray->d_dist[H];
	ray->s_dist[V] = (cast->step[Y] > 0
		? ray->m_pos[Y] - cam->pos[Y] + 1
		: cam->pos[Y] - ray->m_pos[Y]) * ray->d_dist[V];
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

static void		wall_search(t_ray *ray, t_cast *cast, t_env *env, int *wall_hit)
{
	while (*wall_hit == No)
	{
		if (ray->s_dist[H] < ray->s_dist[V])
		{
			ray->s_dist[H] += ray->d_dist[H];
			ray->m_pos[X] += cast->step[X];
			ray->side = H;
		}
		else
		{
			ray->s_dist[V] += ray->d_dist[V];
			ray->m_pos[Y] += cast->step[Y];
			ray->side = V;
		}
		if (env->map->level[ray->m_pos[Y]][ray->m_pos[X]] > '0')
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

void			cast_a_ray(t_cast *cast, t_cam *cam, t_env *env )
{
	int			wall_hit;

	set_values(cast->ray, cast, cam, &wall_hit);
	wall_search(cast->ray, cast, env, &wall_hit);
	if (wall_hit == Yes)
	{
		cast->distance = (cast->ray->side == H
			? (cast->ray->m_pos[X] - cam->pos[X]
				+ (1 - cast->step[X]) / 2) / cast->ray->v_dir[X]
			: (cast->ray->m_pos[Y] - cam->pos[Y] +
				(1 - cast->step[Y]) / 2) / cast->ray->v_dir[Y]);
		cast->wall_height = (int)floor(HEIGHT * 1.27 / cast->distance);
	}
}
