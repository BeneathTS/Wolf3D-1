/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:41 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/15 23:32:42 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void set_alpha(char *data, int width, int height, unsigned int alpha_value)
{
	int x;
	int y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			((int *)data)[y * width + x] |= (alpha_value << 24);
	}
}

static void draw_buttons(t_env *env)
{
	if ((env->menu->sel_button == '1' && env->menu->tex->id == '5') || 
	(env->menu->tex->id == '1' && env->menu->sel_button != '1'))
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 
		(WIDTH >> 1) - 49, (HEIGHT >> 1) - 119);
	if ((env->menu->sel_button == '2' && env->menu->tex->id == '6') || 
	(env->menu->tex->id == '2' && env->menu->sel_button != '2'))
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 
		(WIDTH >> 1) - 8, (HEIGHT >> 1) - 52);
	if ((env->menu->sel_button == '3' && env->menu->tex->id == '7') || 
	(env->menu->tex->id == '3' && env->menu->sel_button != '3'))
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 
		(WIDTH >> 1) - 18, (HEIGHT >> 1) + 14);
	if ((env->menu->sel_button == '4' && env->menu->tex->id == '8') || 
	(env->menu->tex->id == '4' && env->menu->sel_button != '4'))
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 
		(WIDTH >> 1) - 78, (HEIGHT >> 1) + 80);
}

void draw_menu(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);

	env->menu->tex = env->menu->first;
	mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, env->menu->bg_off[X], env->menu->bg_off[Y]);
	while ((env->menu->tex = env->menu->tex->next))
	{
		if (env->menu->tex->id == 'L')
			mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, (WIDTH >> 1) - 337, (HEIGHT >> 1) - 169);
		if (env->menu->tex->id == 'W')
			mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, (WIDTH >> 1) - 278, (HEIGHT >> 1) - 100);
		draw_buttons(env);
	}
}