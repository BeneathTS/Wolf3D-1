/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_data_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:38 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/04 20:32:44 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char	*get_image(int ct)
{
	if (ct == 0)
		return (BT1);
	else if (ct == 1)
		return (BT2);
	else if (ct == 2)
		return (BT3);
	else if (ct == 3)
		return (BT4);
	else if (ct == 4)
		return (BT1_ACTIVE);
	else if (ct == 5)
		return (BT2_ACTIVE);
	else if (ct == 6)
		return (BT3_ACTIVE);
	else if (ct == 7)
		return (BT4_ACTIVE);
	return (NULL);
}

static void	load_buttons(t_env *env)
{
	int ct;

	ct = -1;
	while (++ct < 8)
	{
		env->menu->main->next = tex_init(env->menu->main, NULL);
		env->menu->main = env->menu->main->next;
		if (!(env->menu->main->tex_ptr = mlx_xpm_file_to_image(env->mlx,
		get_image(ct), &env->menu->main->width, &env->menu->main->height)))
			ft_exit(ERROR_MSG);
		env->menu->main->data = mlx_get_data_addr(env->menu->main->tex_ptr,
			&env->menu->main->bts_pr_px, &env->menu->main->sz_ln,
			&env->menu->main->endian);
		env->menu->main->id = '1' + ct;
		if (ct < 4)
			set_alpha(env->menu->main->data, env->menu->main->width,
				env->menu->main->height, BUTTONS_ALPHA);
	}
}

static void	load_logo(t_env *env)
{
	env->menu->main->next = tex_init(env->menu->main, NULL);
	env->menu->main = env->menu->main->next;
	if (!(env->menu->main->tex_ptr = mlx_xpm_file_to_image(env->mlx,
	LG_IMG, &env->menu->main->width, &env->menu->main->height)))
		ft_exit(ERROR_MSG);
	env->menu->main->data = mlx_get_data_addr(env->menu->main->tex_ptr,
	&env->menu->main->bts_pr_px, &env->menu->main->sz_ln,
	&env->menu->main->endian);
	env->menu->main->id = 'L';
	set_alpha(env->menu->main->data, env->menu->main->width,
	env->menu->main->height, LOGO_ALPHA);
	env->menu->main->next = tex_init(env->menu->main, NULL);
	env->menu->main = env->menu->main->next;
	if (!(env->menu->main->tex_ptr = mlx_xpm_file_to_image(env->mlx,
	LG_BASE, &env->menu->main->width, &env->menu->main->height)))
		ft_exit(ERROR_MSG);
	env->menu->main->data = mlx_get_data_addr(env->menu->main->tex_ptr,
	&env->menu->main->bts_pr_px, &env->menu->main->sz_ln,
	&env->menu->main->endian);
	env->menu->main->id = 'W';
}

void		load_menu_data(t_env *env)
{
	if (!(env->menu->main->tex_ptr = mlx_xpm_file_to_image(env->mlx,
	BG_IMG, &env->menu->main->width, &env->menu->main->height)))
		ft_exit(ERROR_MSG);
	env->menu->main->data = mlx_get_data_addr(env->menu->main->tex_ptr,
		&env->menu->main->bts_pr_px, &env->menu->main->sz_ln,
		&env->menu->main->endian);
	env->menu->main->id = 'B';
	env->menu->first_tex[Menu] = env->menu->main;
	load_logo(env);
	load_buttons(env);
	load_back_button(env);
	load_refresh_button(env);
}
