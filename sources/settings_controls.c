/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:34:47 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/21 13:40:24 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define MENU env->menu
#define CONTROLS MENU->controls

static void	change_values(t_env *env)
{
	if (CONTROLS->pressed[0])
		env->cam->m_speed = (float)(CONTROLS->m_pos - 208) / 402;
	else if (CONTROLS->pressed[1])
		env->cam->r_speed = (float)(CONTROLS->r_pos - 208) / 134;
}

void		move_rollers(int x, int y, t_env *env)
{
	int		*value;

	if (CONTROLS->pressed[0])
		value = &CONTROLS->m_pos;
	else if (CONTROLS->pressed[1])
		value = &CONTROLS->r_pos;
	else if (CONTROLS->pressed[2])
		value = &CONTROLS->v_pos;
	else if (CONTROLS->pressed[3])
		value = &CONTROLS->d_pos;
	*value = x - 12;
	if (x > 610 + 12)
		*value = 610;
	if (x < 208 + 12)
		*value = 208;
	change_values(env);
}

static void	check_button_select(int x, int y, t_env *env)
{
	if (x >= (WIDTH - 284) && x <= (WIDTH - 221)
		&& y >= (HEIGHT - 134) && y <= (HEIGHT - 111))
		MENU->sel_button = 'b';
	else
		MENU->sel_button = 0;
}

void		settings_push_buttons(int x, int y, t_env *env)
{
	if (x >= (WIDTH - 284) && x <= (WIDTH - 221)
		&& y >= (HEIGHT - 134) && y <= (HEIGHT - 111))
	{
		env->mode = Menu;
		draw_main_menu(env);
	}
	if (x >= CONTROLS->m_pos && x <= CONTROLS->m_pos + 22
		&& y >= 215 && y <= 235)
		CONTROLS->pressed[0] = Yes;
	if (x >= CONTROLS->r_pos && x <= CONTROLS->r_pos + 22
		&& y >= 409 && y <= 429)
		CONTROLS->pressed[1] = Yes;
	if (x >= CONTROLS->v_pos && x <= CONTROLS->v_pos + 22
		&& y >= 583 && y <= 603)
		CONTROLS->pressed[2] = Yes;
	if (x >= CONTROLS->d_pos && x <= CONTROLS->d_pos + 22
		&& y >= 757 && y <= 777)
		CONTROLS->pressed[3] = Yes;
}

void		settings_controls(int x, int y, t_env *env)
{
	bg_paralax(x, y, env);
	check_button_select(x, y, env);
	if (CONTROLS->pressed[0] || CONTROLS->pressed[1] ||
		CONTROLS->pressed[2] || CONTROLS->pressed[3])
		move_rollers(x, y, env);
	draw_settings(env);
}
