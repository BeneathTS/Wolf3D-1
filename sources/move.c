/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 07:25:32 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/11 05:06:44 by sleonia          ###   ########.fr       */
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

void			player_move(int key, t_env *env)
{
	if (key == KB_W)
	{
		collisions_x(env, &env->cam->pos[X], env->cam->pos[Y], 1);
		collisions_y(env, env->cam->pos[X], &env->cam->pos[Y], 1);
	}
	if (key == KB_A)
	{
		//
	}
	if (key == KB_S)
	{
		collisions_x(env, &env->cam->pos[X], env->cam->pos[Y], -1);
		collisions_y(env, env->cam->pos[X], &env->cam->pos[Y], -1);
	}
	if (key == KB_D)
	{
		//
	}
	if (env->cam->pos[X] < 1.2)
		env->cam->pos[X] = 1.2;
	if (env->cam->pos[X] > env->map->width - 1.2)
		env->cam->pos[X] = env->map->width - 1.2;
	if (env->cam->pos[Y] < 1.2)
		env->cam->pos[Y] = 1.2;
	if (env->cam->pos[Y] > env->map->height - 1.2)
		env->cam->pos[Y] = env->map->height - 1.2;
	renderer(env);
}
