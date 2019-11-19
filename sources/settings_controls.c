#include "wolf3d.h"

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
}

void settings_controls(int x, int y, t_env *env)
{
	check_button_select(x, y, env);
}