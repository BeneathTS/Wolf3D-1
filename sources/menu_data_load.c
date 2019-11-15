/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_data_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:38 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/15 23:52:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char *get_image(int ct)
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

static void load_buttons(t_env * env)
{
	int ct;

	ct = -1;
	while (++ct < 8)
	{
	env->menu->tex->next = tex_init(env->menu->tex, NULL);
	env->menu->tex = env->menu->tex->next;
	env->menu->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, get_image(ct), &env->menu->tex->width, &env->menu->tex->height);
	env->menu->tex->data = mlx_get_data_addr(env->menu->tex->tex_ptr, &env->menu->tex->bts_pr_px, &env->menu->tex->sz_ln, &env->menu->tex->endian);
	env->menu->tex->id = '1' + ct;
	if (ct < 4)
		set_alpha(env->menu->tex->data, env->menu->tex->width, env->menu->tex->height, BUTTONS_ALPHA);
	}
}

static void load_logo(t_env *env)
{
	env->menu->tex->next = tex_init(env->menu->tex, NULL);
	env->menu->tex = env->menu->tex->next;
	env->menu->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, LG_IMG, &env->menu->tex->width, &env->menu->tex->height);
	env->menu->tex->data = mlx_get_data_addr(env->menu->tex->tex_ptr, &env->menu->tex->bts_pr_px, &env->menu->tex->sz_ln, &env->menu->tex->endian);
	env->menu->tex->id = 'L';
	set_alpha(env->menu->tex->data, env->menu->tex->width, env->menu->tex->height, LOGO_ALPHA);

	env->menu->tex->next = tex_init(env->menu->tex, NULL);
	env->menu->tex = env->menu->tex->next;
	env->menu->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, LG_BASE, &env->menu->tex->width, &env->menu->tex->height);
	env->menu->tex->data = mlx_get_data_addr(env->menu->tex->tex_ptr, &env->menu->tex->bts_pr_px, &env->menu->tex->sz_ln, &env->menu->tex->endian);
	env->menu->tex->id = 'W';
}

static void load_chooser_scroll(t_env *env)
{
	env->menu->chsr = tex_init(NULL, NULL);
	env->menu->chsr->tex_ptr = mlx_xpm_file_to_image(env->mlx, SCRL, &env->menu->chsr->width, &env->menu->chsr->height);
	env->menu->chsr->data = mlx_get_data_addr(env->menu->chsr->tex_ptr, &env->menu->chsr->bts_pr_px, &env->menu->chsr->sz_ln, &env->menu->chsr->endian);
	env->menu->chsr->id = 'S';
}

void load_menu_data(t_env * env)
{
	env->menu->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, BG_IMG, &env->menu->tex->width, &env->menu->tex->height);
	env->menu->tex->data = mlx_get_data_addr(env->menu->tex->tex_ptr, &env->menu->tex->bts_pr_px, &env->menu->tex->sz_ln, &env->menu->tex->endian);
	env->menu->tex->id = 'B';

	env->menu->first = env->menu->tex;

	load_logo(env);
	load_buttons(env);
	load_chooser_scroll(env);
}