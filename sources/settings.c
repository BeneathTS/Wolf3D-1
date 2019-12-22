/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:33:04 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/03 19:38:52 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_titles(t_env *env, t_tex *sttngs)
{
	if (env->menu->settings->id == 'M')
		mlx_put_image_to_window(env->mlx, env->win, sttngs->tex_ptr, 218, 148);
	if (env->menu->settings->id == 'R')
		mlx_put_image_to_window(env->mlx, env->win, sttngs->tex_ptr, 218, 327);
	if (env->menu->settings->id == 'V')
		mlx_put_image_to_window(env->mlx, env->win, sttngs->tex_ptr, 218, 506);
	if (env->menu->settings->id == 'D')
		mlx_put_image_to_window(env->mlx, env->win, sttngs->tex_ptr, 218, 685);
}

static void	draw_rollers_and_titles(t_env *env, t_menu_controls *c, t_tex *s)
{
	if (env->menu->settings->id >= 'A' && env->menu->settings->id <= 'Z')
		draw_titles(env, s);
	if (env->menu->settings->id == '1')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, c->m_pos, 212);
	if (env->menu->settings->id == '2')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, c->r_pos, 406);
	if (env->menu->settings->id == '3')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, c->v_pos, 581);
	if (env->menu->settings->id == '4')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, c->d_pos, 756);
	if (env->menu->settings->id == '5')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, 218, 222);
	if (env->menu->settings->id == '6')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, 218, 416);
	if (env->menu->settings->id == '7')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, 218, 591);
	if (env->menu->settings->id == '8')
		mlx_put_image_to_window(env->mlx, env->win, s->tex_ptr, 218, 766);
}

void		draw_settings(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	env->menu->settings = env->menu->first_tex[Settings];
	mlx_put_image_to_window(env->mlx, env->win,
	env->menu->first_tex[Menu]->tex_ptr,
	env->menu->bg_off[X], env->menu->bg_off[Y]);
	draw_rollers_and_titles(env, env->menu->controls, env->menu->settings);
	while ((env->menu->settings = env->menu->settings->next))
		draw_rollers_and_titles(env, env->menu->controls, env->menu->settings);
	draw_add_buttons(env);
}
