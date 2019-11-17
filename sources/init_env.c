/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:18 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/17 07:24:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		draw_scroll_base(t_menu *menu)
{
	int y;
	int finish;

	y = -1;
	finish = 645;
	while (++y < finish)
		((int *)menu->scroll->img_data)[y] = 0xCDFFFFFF;
}

t_menu			*menu_data_init(t_env *env)
{
	t_menu		*menu;

	if (!(menu = (t_menu *)malloc(sizeof(t_menu))))
		ft_exit(ERROR_MSG);
	menu->bg_off[X] = -93;
	menu->bg_off[Y] = -63;
	menu->tex = tex_init(NULL, NULL);
	(void)env;
	if (!(menu->scroll = (t_scroll *)malloc(sizeof(t_scroll))))
		ft_exit(ERROR_MSG);
	menu->scroll->img_ptr = mlx_new_image(env->mlx, 1, 645);
	menu->scroll->img_data = mlx_get_data_addr(menu->scroll->img_ptr,
		&menu->scroll->bts_pr_px, &menu->scroll->sz_ln, &menu->scroll->endian);
	menu->scroll->offset = 0;
	draw_scroll_base(menu);
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
	env->menu = menu_data_init(env);
	return (env);
}
