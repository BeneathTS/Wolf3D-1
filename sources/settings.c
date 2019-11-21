/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:33:04 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/21 13:34:00 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define SETTINGS env->menu->settings
#define TEX_PTR SETTINGS->tex_ptr
#define MENU env->menu

static void	draw_back_button(t_env *env)
{
	if (MENU->sel_button == 'b')
		mlx_put_image_to_window(env->mlx, env->win,
			MENU->back_button->prev->tex_ptr, WIDTH - 284, HEIGHT - 134);
	else
		mlx_put_image_to_window(env->mlx, env->win,
			MENU->back_button->tex_ptr, WIDTH - 284, HEIGHT - 134);
}

static void	draw_titles(t_env *env)
{
	if (MENU->settings->id == 'M')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 148);
	if (SETTINGS->id == 'R')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 327);
	if (SETTINGS->id == 'V')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 506);
	if (SETTINGS->id == 'D')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 685);
}

static void	draw_rollers_and_titles(t_env *env)
{
	if (SETTINGS->id >= 'A' && SETTINGS->id <= 'Z')
		draw_titles(env);
	if (SETTINGS->id == '1')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR,
			MENU->controls->m_pos, 212);
	if (SETTINGS->id == '2')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR,
			MENU->controls->r_pos, 406);
	if (SETTINGS->id == '3')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR,
			MENU->controls->v_pos, 581);
	if (SETTINGS->id == '4')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR,
			MENU->controls->d_pos, 756);
	if (SETTINGS->id == '5')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 222);
	if (SETTINGS->id == '6')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 416);
	if (SETTINGS->id == '7')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 591);
	if (SETTINGS->id == '8')
		mlx_put_image_to_window(env->mlx, env->win, TEX_PTR, 218, 766);
}

void		draw_settings(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	SETTINGS = MENU->first_tex[Settings];
	mlx_put_image_to_window(env->mlx, env->win,
		MENU->first_tex[Menu]->tex_ptr, MENU->bg_off[X], MENU->bg_off[Y]);
	draw_rollers_and_titles(env);
	while ((SETTINGS = SETTINGS->next))
		draw_rollers_and_titles(env);
	draw_back_button(env);
}
