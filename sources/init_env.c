/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/03 19:17:19 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_menu			*menu_data_init(t_env *env)
{
	t_menu		*menu;

	if (!(menu = (t_menu *)malloc(sizeof(t_menu))))
		ft_exit(ERROR_MSG);
	menu->bg_off[X] = -350 * (WIDTH / HEIGHT);
	menu->bg_off[Y] = -400 * (WIDTH / HEIGHT);
	menu->main = tex_init(NULL, NULL);
	menu->chooser = tex_init(NULL, NULL);
	menu->settings = tex_init(NULL, NULL);
	menu->cards = NULL;
	if (!(menu->controls = (t_menu_controls *)malloc(sizeof(t_menu_controls))))
		ft_exit(ERROR_MSG);
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

	if (!(cntrls = (t_cntrls *)malloc(sizeof(t_cntrls))))
		ft_exit(ERROR_MSG);
	cntrls->angle = 0.0;
	cntrls->old_coord[X] = 0;
	cntrls->old_coord[Y] = 0;
	return (cntrls);
}

t_env			*env_init(t_map *map)
{
	t_env		*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		ft_exit(ERROR_MSG);
	env->map = map;
	env->tex = NULL;
	env->cam = cam_init();
	env->cast = cast_init();
	env->cntrls = cntrls_init();
	env->mode = Menu;
	if (!(env->mlx = mlx_init()))
		ft_exit(ERROR_MSG);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D")))
		ft_exit(ERROR_MSG);
	if (!(env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
		ft_exit(ERROR_MSG);
	if (!(env->data_addr = mlx_get_data_addr(env->img,
		&env->bts_pr_px, &env->sz_ln, &env->endian)))
		ft_exit(ERROR_MSG);
	init_sdl_music(env->music, &env->volume);
	printf("%d\n", env->volume);
	env->menu = menu_data_init(env);
	return (env);
}
