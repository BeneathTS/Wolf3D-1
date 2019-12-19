/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:25:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/19 06:58:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		collisions_x(t_env *env, double *x, int y, char sign)
{
	int			wall;
	double		step;

	step = *x + sign * env->cam->c_v_dir[X] * env->cam->m_speed;
	if (env->map->level[y][(int)step] != '0')
	{
		wall = floor(step);
		*x = (wall - sign * 0.2);
	}
	else if (env->map->level[y][(int)(step + 0.2)] != '0')
	{
		wall = ceil(step);
		*x = (wall - 0.2);
	}
	else if (env->map->level[y][(int)(step - 0.2)] != '0')
	{
		wall = floor(step);
		*x = (wall + 0.2);
	}
	else
		*x = step;
}

static void		collisions_y(t_env *env, int x, double *y, char sign)
{
	int			wall;
	double		step;

	step = *y + sign * env->cam->c_v_dir[Y] * env->cam->m_speed;
	if (env->map->level[(int)step][x] != '0')
	{
		wall = floor(step);
		*y = (wall - sign * 0.2);
	}
	else if (env->map->level[(int)(step + 0.2)][x] != '0')
	{
		wall = ceil(step);
		*y = (wall - 0.2);
	}
	else if (env->map->level[(int)(step - 0.2)][x] != '0')
	{
		wall = floor(step);
		*y = (wall + 0.2);
	}
	else
		*y = step;
}

static void		move_sidestep(t_env *env, double *x, double *y, char sign)
{
// printf("%f    %f\n", env->cam->c_v_dir[X], env->cam->c_v_dir[Y]);
	if (env->cam->c_v_dir[X] > 0 && env->cam->c_v_dir[Y] > 0)
	{
		*x = *x + 0.5 * env->cam->m_speed * sign;
		*y = *y - 0.5 * env->cam->m_speed * sign;
	}
	else if (env->cam->c_v_dir[X] < 0 && env->cam->c_v_dir[Y] > 0)
	{
		*x = *x + 0.5 * env->cam->m_speed * sign;
		*y = *y + 0.5 * env->cam->m_speed * sign;
	}
	else if (env->cam->c_v_dir[X] > 0 && env->cam->c_v_dir[Y] < 0)
	{
		*x = *x - 0.5 * env->cam->m_speed * sign;
		*y = *y - 0.5 * env->cam->m_speed * sign;
	}
	else if (env->cam->c_v_dir[X] < 0 && env->cam->c_v_dir[Y] < 0)
	{
		*x = *x - 0.5 * env->cam->m_speed * sign;
		*y = *y + 0.5 * env->cam->m_speed * sign;
	}
	else if (env->cam->c_v_dir[X] == 0)
		*x = *x - 0.5 * env->cam->m_speed * sign;
	else if (env->cam->c_v_dir[Y] == 0)
		*y = *y - 0.5 * env->cam->m_speed * sign;
}

void			checking_map_borders(t_cam *cam, t_map *map)
{
	if (cam->pos[X] < 1.2)
		cam->pos[X] = 1.2;
	if (cam->pos[X] > map->width - 1.2)
		cam->pos[X] = map->width - 1.2;
	if (cam->pos[Y] < 1.2)
		cam->pos[Y] = 1.2;
	if (cam->pos[Y] > map->height - 1.2)
		cam->pos[Y] = map->height - 1.2;
}

void			player_move(int key, t_env *env)
{
	if (key == KB_W)
	{
		collisions_x(env, &env->cam->pos[X], env->cam->pos[Y], 1);
		collisions_y(env, env->cam->pos[X], &env->cam->pos[Y], 1);
	}
	if (key == KB_A)
	{
		move_sidestep(env, &env->cam->pos[X], &env->cam->pos[Y], 1);
		collisions_x(env, &env->cam->pos[X], env->cam->pos[Y], 0);
		collisions_y(env, env->cam->pos[X], &env->cam->pos[Y], 0);
	}
	if (key == KB_S)
	{
		collisions_x(env, &env->cam->pos[X], env->cam->pos[Y], -1);
		collisions_y(env, env->cam->pos[X], &env->cam->pos[Y], -1);
	}
	if (key == KB_D)
	{
		move_sidestep(env, &env->cam->pos[X], &env->cam->pos[Y], -1);
		collisions_x(env, &env->cam->pos[X], env->cam->pos[Y], 0);
		collisions_y(env, env->cam->pos[X], &env->cam->pos[Y], 0);
	}
	checking_map_borders(env->cam, env->map);
}
