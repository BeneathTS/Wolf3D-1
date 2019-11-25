/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:13 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/25 23:48:19 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	rotate(int key, t_env *env)
{
	if (key == ARR_LFT || key == KB_A)
		env->cntrls->angle -= 0.01;
	if (key == ARR_RGHT || key == KB_D)
		env->cntrls->angle += 0.01;
	if (key == ARR_DOWN)
		env->cam->view_height += 20;
	if (key == ARR_UP)
		env->cam->view_height -= 20;
	env->cam->c_v_dir[X] = env->cam->v_dir[X] *
		cos(env->cntrls->angle * env->cam->r_speed) - env->cam->v_dir[Y]
			* sin(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_dir[Y] = env->cam->v_dir[X] * sin(env->cntrls->angle
		* env->cam->r_speed) + env->cam->v_dir[Y]
			* cos(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_plane[X] = env->cam->v_plane[X]
		* cos(env->cntrls->angle * env->cam->r_speed) - env->cam->v_plane[Y]
			* sin(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_plane[Y] = env->cam->v_plane[X] * sin(env->cntrls->angle
		* env->cam->r_speed) + env->cam->v_plane[Y]
			* cos(env->cntrls->angle * env->cam->r_speed);
	renderer(env);
}

int			key_press(int key, t_env *env)
{
	if (key == ESC)
		x_close(env);
	if (env->mode != Game)
		return (0);
	if (key == ARR_DOWN || key == ARR_LFT || key == ARR_RGHT ||
	key == ARR_UP || key == KB_A || key == KB_D)
		rotate(key, env);
	if (key == KB_W || key == KB_S)
		player_move(key, env);
	return (0);
}

int			mouse_move(int x, int y, t_env *env)
{
	if (env->mode == Menu)
		menu_controls(x, y, env);
	if (env->mode == Settings)
		settings_controls(x, y, env);
	if (env->mode == Choose)
		chooser_controls(x, y, env);
	if (env->mode == Game)
	{
			env->cntrls->angle = x * 0.001;
			env->cam->view_height = y * 3;

			env->cam->c_v_dir[X] = env->cam->v_dir[X] *
		cos(env->cntrls->angle * env->cam->r_speed) - env->cam->v_dir[Y]
			* sin(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_dir[Y] = env->cam->v_dir[X] * sin(env->cntrls->angle
		* env->cam->r_speed) + env->cam->v_dir[Y]
			* cos(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_plane[X] = env->cam->v_plane[X]
		* cos(env->cntrls->angle * env->cam->r_speed) - env->cam->v_plane[Y]
			* sin(env->cntrls->angle * env->cam->r_speed);
	env->cam->c_v_plane[Y] = env->cam->v_plane[X] * sin(env->cntrls->angle
		* env->cam->r_speed) + env->cam->v_plane[Y]
			* cos(env->cntrls->angle * env->cam->r_speed);
			renderer(env);
	}
	return (0);
}

int			mouse_release(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->menu->controls->pressed[0] = 0;
		env->menu->controls->pressed[1] = 0;
		env->menu->controls->pressed[2] = 0;
		env->menu->controls->pressed[3] = 0;
		env->menu->controls->pressed[4] = 0;
	}
	return (0);
}

void		init_key_hooks(t_env *env)
{
	mlx_hook(env->win, 17, 0, x_close, env);
	mlx_hook(env->win, 2, 0, key_press, env);
	mlx_hook(env->win, 4, 0, push_buttons, env);
	mlx_hook(env->win, 5, 0, mouse_release, env);
	mlx_hook(env->win, 6, 0, mouse_move, env);
}
