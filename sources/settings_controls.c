/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_controls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:18:12 by ahiroko           #+#    #+#             */
/*   Updated: 2019/12/06 21:35:17 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	change_values(t_env *env)
{
	if (env->menu->controls->pressed[0])
		env->cam->m_speed = (float)(env->menu->controls->m_pos - 208)
		/ 574.2857143;
	else if (env->menu->controls->pressed[1])
		env->cam->r_speed = (float)(env->menu->controls->r_pos - 208) / 134;
	else if (env->menu->controls->pressed[2])
		env->volume =
		Mix_VolumeMusic((env->menu->controls->v_pos - 208) / 3.140625);
}

void		move_rollers(int x, int y, t_env *env)
{
	int *value;

	if (env->menu->controls->pressed[0])
		value = &env->menu->controls->m_pos;
	else if (env->menu->controls->pressed[1])
		value = &env->menu->controls->r_pos;
	else if (env->menu->controls->pressed[2])
		value = &env->menu->controls->v_pos;
	else if (env->menu->controls->pressed[3])
		value = &env->menu->controls->d_pos;
	*value = x - 12;
	if (x > 610 + 12)
		*value = 610;
	if (x < 208 + 12)
		*value = 208;
	change_values(env);
}

void		settings_push_buttons(int x, int y, t_env *env)
{
	check_push_add_buttons(x, y, env);
	if (x >= env->menu->controls->m_pos &&
	x <= env->menu->controls->m_pos + 22 && y >= 215 && y <= 235)
		env->menu->controls->pressed[0] = Yes;
	if (x >= env->menu->controls->r_pos &&
	x <= env->menu->controls->r_pos + 22 && y >= 409 && y <= 429)
		env->menu->controls->pressed[1] = Yes;
	if (x >= env->menu->controls->v_pos &&
	x <= env->menu->controls->v_pos + 22 && y >= 583 && y <= 603)
		env->menu->controls->pressed[2] = Yes;
	if (x >= env->menu->controls->d_pos &&
	x <= env->menu->controls->d_pos + 22 && y >= 757 && y <= 777)
		env->menu->controls->pressed[3] = Yes;
}

void		settings_controls(int x, int y, t_env *env)
{
	// bg_paralax(x, y, env);
	check_add_button_select(x, y, env);
	if (env->menu->controls->pressed[0] || env->menu->controls->pressed[1] ||
		env->menu->controls->pressed[2] || env->menu->controls->pressed[3])
		move_rollers(x, y, env);
	draw_settings(env);
}
