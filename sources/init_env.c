/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/17 15:25:21 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_menu			*menu_data_init(t_env *env)
{
	t_menu		*menu;

	menu = (t_menu *)ft_safe_malloc(sizeof(t_menu));
	menu->bg_off[X] = -350 * (WIDTH / HEIGHT);
	menu->bg_off[Y] = -400 * (WIDTH / HEIGHT);
	menu->main = tex_init(NULL, NULL);
	menu->chooser = tex_init(NULL, NULL);
	menu->settings = tex_init(NULL, NULL);
	menu->cards = NULL;
	menu->controls =
		(t_menu_controls *)ft_safe_malloc(sizeof(t_menu_controls));
	menu->controls->m_pos = 208 + 402 * env->cam->m_speed;
	menu->controls->r_pos = 208 + 134 * env->cam->r_speed;
	menu->controls->v_pos = 208 + 3.140625 * env->volume;
	menu->controls->d_pos = 208;
	menu->controls->s_pos = 79;
	menu->controls->pressed[0] = No;
	menu->controls->pressed[1] = No;
	menu->controls->pressed[2] = No;
	menu->controls->pressed[3] = No;
	menu->controls->pressed[4] = No;
	return (menu);
}

t_cntrls		*cntrls_init(void)
{
	t_cntrls	*cntrls;

	cntrls = (t_cntrls *)ft_safe_malloc(sizeof(t_cntrls));
	cntrls->angle = 0.0;
	cntrls->old_coord[X] = 0;
	cntrls->old_coord[Y] = 0;
	return (cntrls);
}

t_env			*env_init(void)
{
	t_env		*env;

	env = (t_env*)ft_safe_malloc(sizeof(t_env));
	env->map = NULL;
	env->tex = NULL;
	env->cam = cam_init();
	env->cast = cast_init();
	env->cntrls = cntrls_init();
	env->mode = Menu;
	if (!(env->mlx = mlx_init()))
		ft_exit(ENV_INIT);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D")))
		ft_exit(ENV_INIT);
	if (!(env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
		ft_exit(ENV_INIT);
	if (!(env->data_addr = mlx_get_data_addr(env->img,
		&env->bts_pr_px, &env->sz_ln, &env->endian)))
		ft_exit(ENV_INIT);
	// init_sdl_music(env->music, &env->volume);
	env->menu = menu_data_init(env);
	return (env);
}
