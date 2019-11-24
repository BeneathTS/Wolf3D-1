/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:41 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/25 00:57:07 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define MENU env->menu

void			set_alpha(char *data, int width, int height,
					unsigned int alpha_value)
{
	int	x;
	int	y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			((int *)data)[y * width + x] |= (alpha_value << 24);
	}
}

static void		draw_controls_and_logo(t_env *env)
{
	if (MENU->main->id == 'L')
		mlx_put_image_to_window(env->mlx, env->win, MENU->main->tex_ptr,
		(WIDTH >> 1) - 337, (HEIGHT >> 1) - 169);
	if (MENU->main->id == 'W')
		mlx_put_image_to_window(env->mlx, env->win, MENU->main->tex_ptr,
		(WIDTH >> 1) - 278, (HEIGHT >> 1) - 100);
	if ((MENU->sel_button == '1' && MENU->main->id == '5') ||
	(MENU->main->id == '1' && MENU->sel_button != '1'))
		mlx_put_image_to_window(env->mlx, env->win, MENU->main->tex_ptr,
		(WIDTH >> 1) - 49, (HEIGHT >> 1) - 119);
	if ((MENU->sel_button == '2' && MENU->main->id == '6') ||
	(MENU->main->id == '2' && MENU->sel_button != '2'))
		mlx_put_image_to_window(env->mlx, env->win, MENU->main->tex_ptr,
		(WIDTH >> 1) - 8, (HEIGHT >> 1) - 52);
	if ((MENU->sel_button == '3' && MENU->main->id == '7') ||
	(MENU->main->id == '3' && MENU->sel_button != '3'))
		mlx_put_image_to_window(env->mlx, env->win, MENU->main->tex_ptr,
		(WIDTH >> 1) - 18, (HEIGHT >> 1) + 14);
	if ((MENU->sel_button == '4' && MENU->main->id == '8') ||
	(MENU->main->id == '4' && MENU->sel_button != '4'))
		mlx_put_image_to_window(env->mlx, env->win, MENU->main->tex_ptr,
		(WIDTH >> 1) - 78, (HEIGHT >> 1) + 80);
}

void			draw_main_menu(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	MENU->main = MENU->first_tex[Menu];
	mlx_put_image_to_window(env->mlx, env->win, MENU->main->tex_ptr,
		MENU->bg_off[X], MENU->bg_off[Y]);
	while ((MENU->main = MENU->main->next))
		draw_controls_and_logo(env);
}
