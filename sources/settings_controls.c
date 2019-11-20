#include "wolf3d.h"

static void change_values(t_env *env)
{
	if (env->menu->controls->pressed[0])
		env->cam->m_speed = (float)(env->menu->controls->m_pos - 208) / 402;
	else if (env->menu->controls->pressed[1])
		env->cam->r_speed = (float)(env->menu->controls->r_pos - 208) / 134;
}

void move_rollers(int x, int y, t_env *env)
{
	if (env->menu->controls->pressed[0])
	{
		env->menu->controls->m_pos = x - 12;
		if (x > 610 + 12)
			env->menu->controls->m_pos = 610;
		if (x < 208 + 12)
			env->menu->controls->m_pos = 208;
	}
	else if (env->menu->controls->pressed[1])
	{
		env->menu->controls->r_pos = x - 12;
		if (x > 610 + 12)
			env->menu->controls->r_pos = 610;
		if (x < 208 + 12)
			env->menu->controls->r_pos = 208;
	}
	else if (env->menu->controls->pressed[2])
	{
		env->menu->controls->v_pos = x - 12;
		if (x > 610 + 12)
			env->menu->controls->v_pos = 610;
		if (x < 208 + 12)
			env->menu->controls->v_pos = 208;
	}
	change_values(env);
}

static void check_button_select(int x, int y, t_env *env)
{
	if (x >= (WIDTH - 284) && x <= (WIDTH - 221) && y >= (HEIGHT - 134) && y <= (HEIGHT - 111))
		env->menu->sel_button = 'b';
	else
		env->menu->sel_button = 0;
}

void settings_push_buttons(int x, int y, t_env *env)
{
	if (x >= (WIDTH - 284) && x <= (WIDTH - 221) && y >= (HEIGHT - 134) && y <= (HEIGHT - 111))
	{
		env->mode = Menu;
		draw_main_menu(env);
	}
	if (x >= env->menu->controls->m_pos && x <= env->menu->controls->m_pos + 22 && y >= 215 && y <= 235)
		env->menu->controls->pressed[0] = Yes;
	if (x >= env->menu->controls->r_pos && x <= env->menu->controls->r_pos + 22 && y >= 409 && y <= 429)
		env->menu->controls->pressed[1] = Yes;
	if (x >= env->menu->controls->v_pos && x <= env->menu->controls->v_pos + 22 && y >= 583 && y <= 603)
		env->menu->controls->pressed[2] = Yes;
}

void settings_controls(int x, int y, t_env *env)
{
	bg_paralax(x, y, env);
	check_button_select(x, y, env);
	if (env->menu->controls->pressed[0] || env->menu->controls->pressed[1] ||
		env->menu->controls->pressed[2])
		move_rollers(x, y, env);
	draw_settings(env);
}