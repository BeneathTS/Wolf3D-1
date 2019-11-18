/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/18 07:41:43 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

// fix dat
void bg_paralax(int x, int y, t_env *env)
{
	if (x > (WIDTH >> 1))
		env->menu->bg_off[X] = ((x - (WIDTH >> 2)) * 0.02) - 350 * (WIDTH / HEIGHT);
	if (x < (WIDTH >> 1))
		env->menu->bg_off[X] = ((x - (WIDTH >> 2)) * 0.02) - 350 * (WIDTH / HEIGHT);
	if (y > (HEIGHT >> 1))
		env->menu->bg_off[Y] = ((y - (HEIGHT >> 2)) * 0.02) - 400 * (WIDTH / HEIGHT);
	if (y < (HEIGHT >> 1))
		env->menu->bg_off[Y] = ((y - (HEIGHT >> 2)) * 0.02) - 400 * (WIDTH / HEIGHT);
}

void check_button_select(int x, int y, t_env *env)
{
	if (x >= (WIDTH >> 1) - 49 && x <= (WIDTH >> 1) + 335 && 
	y >= (HEIGHT >> 1) - 117 && y <= (HEIGHT >> 1) - 59)
		env->menu->sel_button = '1';
	else if ((WIDTH >> 1) - 8 && x <= (WIDTH >> 1) + 335 && 
	y >= (HEIGHT >> 1) - 50 && y <= (HEIGHT >> 1) + 8)
		env->menu->sel_button = '2';
	else if (x >= (WIDTH >> 1) - 18 && x <= (WIDTH >> 1) + 335 && 
	y >= (HEIGHT >> 1) + 16 && y <= (HEIGHT >> 1) + 74)
		env->menu->sel_button = '3';
	else if (x >= (WIDTH >> 1) - 78 && x <= (WIDTH >> 1) + 335 && 
	y >= (HEIGHT >> 1) + 82 && y <= (HEIGHT >> 1) + 140)
		env->menu->sel_button = '4';
	else
		env->menu->sel_button = 0;
}

int push_buttons(int button, int x, int y, t_env *env)
{
	if (button == 1 && x >= (WIDTH >> 1) - 49 && x <= (WIDTH >> 1) + 335 && y >= (HEIGHT >> 1) - 117 && y <= (HEIGHT >> 1) - 59)
	{
		env->mode = Game;
		// env->mode = Choose;
		renderer(env);
		//draw_chooser(env);
	}
	if (button == 1 && x >= (WIDTH >> 1) - 78 && x <= (WIDTH >> 1) + 335 && y >= (HEIGHT >> 1) + 82 && y <= (HEIGHT >> 1) + 140)
		x_close(env);
	return (0);
}