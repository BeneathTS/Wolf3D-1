/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_data_load.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:38 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/21 14:14:55 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define MENU_MAIN env->menu->main
#define BACK_BUTTON env->menu->back_button

static char		*get_image(int ct)
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

static void		load_buttons(t_env *env)
{
	int ct;

	ct = -1;
	while (++ct < 8)
	{
		MENU_MAIN->next = tex_init(MENU_MAIN, NULL);
		MENU_MAIN = MENU_MAIN->next;
		MENU_MAIN->tex_ptr = mlx_xpm_file_to_image(env->mlx, get_image(ct),
			&MENU_MAIN->width, &MENU_MAIN->height);
		MENU_MAIN->data = mlx_get_data_addr(MENU_MAIN->tex_ptr,
			&MENU_MAIN->bts_pr_px, &MENU_MAIN->sz_ln, &MENU_MAIN->endian);
		MENU_MAIN->id = '1' + ct;
		if (ct < 4)
			set_alpha(MENU_MAIN->data, MENU_MAIN->width,
				MENU_MAIN->height, BUTTONS_ALPHA);
	}
}

static void		load_logo(t_env *env)
{
	MENU_MAIN->next = tex_init(MENU_MAIN, NULL);
	MENU_MAIN = MENU_MAIN->next;
	MENU_MAIN->tex_ptr = mlx_xpm_file_to_image(env->mlx, LG_IMG,
		&MENU_MAIN->width, &MENU_MAIN->height);
	MENU_MAIN->data = mlx_get_data_addr(MENU_MAIN->tex_ptr,
		&MENU_MAIN->bts_pr_px, &MENU_MAIN->sz_ln, &MENU_MAIN->endian);
	MENU_MAIN->id = 'L';
	set_alpha(MENU_MAIN->data, MENU_MAIN->width,
		MENU_MAIN->height, LOGO_ALPHA);
	MENU_MAIN->next = tex_init(MENU_MAIN, NULL);
	MENU_MAIN = MENU_MAIN->next;
	MENU_MAIN->tex_ptr = mlx_xpm_file_to_image(env->mlx, LG_BASE,
		&MENU_MAIN->width, &MENU_MAIN->height);
	MENU_MAIN->data = mlx_get_data_addr(MENU_MAIN->tex_ptr,
		&MENU_MAIN->bts_pr_px, &MENU_MAIN->sz_ln, &MENU_MAIN->endian);
	MENU_MAIN->id = 'W';
}

static void		load_back_button(t_env *env)
{
	BACK_BUTTON = tex_init(NULL, NULL);
	BACK_BUTTON->tex_ptr = mlx_xpm_file_to_image(env->mlx, BCK_BTN,
		&BACK_BUTTON->width, &BACK_BUTTON->height);
	BACK_BUTTON->data = mlx_get_data_addr(BACK_BUTTON->tex_ptr,
		&BACK_BUTTON->bts_pr_px, &BACK_BUTTON->sz_ln, &BACK_BUTTON->endian);
	BACK_BUTTON->id = 'Z';
	BACK_BUTTON->next = tex_init(BACK_BUTTON, NULL);
	BACK_BUTTON = BACK_BUTTON->next;
	BACK_BUTTON->tex_ptr = mlx_xpm_file_to_image(env->mlx, BCK_BTN,
		&BACK_BUTTON->width, &BACK_BUTTON->height);
	BACK_BUTTON->data = mlx_get_data_addr(BACK_BUTTON->tex_ptr,
		&BACK_BUTTON->bts_pr_px, &BACK_BUTTON->sz_ln, &BACK_BUTTON->endian);
	BACK_BUTTON->id = 'z';
	set_alpha(BACK_BUTTON->data, BACK_BUTTON->width,
		BACK_BUTTON->height, BUTTONS_ALPHA);
}

void			load_menu_data(t_env *env)
{
	MENU_MAIN->tex_ptr = mlx_xpm_file_to_image(env->mlx, BG_IMG,
		&MENU_MAIN->width, &MENU_MAIN->height);
	MENU_MAIN->data = mlx_get_data_addr(MENU_MAIN->tex_ptr,
		&MENU_MAIN->bts_pr_px, &MENU_MAIN->sz_ln, &MENU_MAIN->endian);
	MENU_MAIN->id = 'B';
	env->menu->first_tex[Menu] = MENU_MAIN;
	load_logo(env);
	load_buttons(env);
	load_back_button(env);
}
