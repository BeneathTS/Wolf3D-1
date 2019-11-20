/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:33:04 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/15 23:58:33 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void draw_back_button(t_env *env)
{
	if (env->menu->sel_button == 'b')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->back_button->prev->tex_ptr, WIDTH - 284, HEIGHT - 134);
	else
		mlx_put_image_to_window(env->mlx, env->win, env->menu->back_button->tex_ptr, WIDTH - 284, HEIGHT - 134);
}

static void draw_titles(t_env *env)
{
	if (env->menu->settings->id == 'M')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 148);
	if (env->menu->settings->id == 'R')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 327);
	if (env->menu->settings->id == 'V')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 506);
	if (env->menu->settings->id == 'D')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 685);
}

static void draw_rollers_and_titles(t_env *env)
{
	if (env->menu->settings->id >= 'A' && env->menu->settings->id <= 'Z')
		draw_titles(env);
	if (env->menu->settings->id == '1')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, env->menu->controls->m_pos, 212);
	if (env->menu->settings->id == '2')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, env->menu->controls->r_pos, 406);
	if (env->menu->settings->id == '3')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, env->menu->controls->v_pos, 581);
	if (env->menu->settings->id == '4')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, env->menu->controls->d_pos, 756);
	if (env->menu->settings->id == '5')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 222);
	if (env->menu->settings->id == '6')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 416);
	if (env->menu->settings->id == '7')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 591);
	if (env->menu->settings->id == '8')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->settings->tex_ptr, 218, 766);
}

void	draw_settings(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	
	env->menu->settings = env->menu->first_tex[Settings];
	mlx_put_image_to_window(env->mlx, env->win, env->menu->first_tex[Menu]->tex_ptr, env->menu->bg_off[X], env->menu->bg_off[Y]);
	draw_rollers_and_titles(env);
	while ((env->menu->settings = env->menu->settings->next))
		draw_rollers_and_titles(env);
	draw_back_button(env);
}
