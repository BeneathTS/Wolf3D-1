/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:13 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/10 08:11:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	rotate(int key, t_env *env)
{
	if (key == ARR_LFT || key == KB_A)
		env->cntrls->angle -= 0.03;
	if (key == ARR_RGHT || key == KB_D)
		env->cntrls->angle += 0.03;
	if (key == ARR_DOWN)
		env->cam->view_height += 40;
	if (key == ARR_UP)
		env->cam->view_height -= 40;
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
	if (key == ESC && env->mode != Game)
		x_close(env);
	if (key == ESC && env->mode == Game)
	{
		env->cam->pos[X] = 1.5;
		env->cam->pos[Y] = 1.5;
		env->mode = Menu;
		env->menu->controls->s_pos = 79;
		resset_card_coords(env);
		// ft_destroy_string_arr(env->map->level);
		ft_free_tex(env);
		draw_main_menu(env);
	}
	if (env->mode != Game)
		return (0);
	if (key == ARR_DOWN || key == ARR_LFT || key == ARR_RGHT ||
	key == ARR_UP || key == KB_A || key == KB_D)
		rotate(key, env);
	if (key == KB_W || key == KB_S)
		player_move(key, env);
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
