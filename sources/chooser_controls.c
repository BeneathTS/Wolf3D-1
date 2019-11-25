#include "wolf3d.h"

static void move_scroller(int y, t_env *env)
{
	env->menu->controls->s_pos = y - 30;
	if (y < 79 + 30)
		env->menu->controls->s_pos = 79;
	if (y > 842 + 30)
		env->menu->controls->s_pos = 842;
}

// static void scroll(int x, int y, t_env *env)
// {
// 	int temp;

// 	temp = env->menu->controls->s_pos;
// 	temp - y;

// }

void push_scroller(int x, int y, t_env *env)
{
	check_push_add_buttons(x, y, env);
	if (x >= WIDTH - 100 && x <= WIDTH - 78 &&
		y >= env->menu->controls->s_pos && y <= env->menu->controls->s_pos + 73)
		env->menu->controls->pressed[4] = Yes;
}

void chooser_controls(int x, int y, t_env *env)
{
	bg_paralax(x, y, env);
	check_back_button_select(x, y, env);
	if (env->menu->controls->pressed[4])
		move_scroller(y, env);
	draw_chooser(env);
}