/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:50 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/15 23:32:51 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void bg_paralax(int x, int y, t_env *env)
{
	if (x > (WIDTH >> 1))
		env->menu->bg_off[X] = ((x - (WIDTH >> 2)) * 0.02) - 93;
	if (x < (WIDTH >> 1))
		env->menu->bg_off[X] = ((x - (WIDTH >> 2)) * 0.02) - 93;
	if (y > (HEIGHT >> 1))
		env->menu->bg_off[Y] = ((y - (HEIGHT >> 2)) * 0.02) - 63;
	if (y < (HEIGHT >> 1))
		env->menu->bg_off[Y] = ((y - (HEIGHT >> 2)) * 0.02) - 63;
}

void check_button_select(int x, int y, t_env *env)
{
	if (x >= 592 && x <= 975 && y >= 243 && y <= 303)
		env->menu->sel_button = '1';
	else if (x >= 633 && x <= 975 && y >= 310 && y <= 370)
		env->menu->sel_button = '2';
	else if (x >= 623 && x <= 975 && y >= 376 && y <= 436)
		env->menu->sel_button = '3';
	else if (x >= 563 && x <= 975 && y >= 442 && y <= 502)
		env->menu->sel_button = '4';
	else
		env->menu->sel_button = 0;
}

int push_buttons(int button, int x, int y, t_env *env)
{
	if (button == 1 && x >= 592 && x <= 975 && y >= 243 && y <= 303)
	{
		env->mode = GAME;
		renderer(env);
	}
	if (button == 1 && x >= 563 && x <= 975 && y >= 442 && y <= 502)
		x_close(env);
	return (0);
}