#include "wolf3d.h"

void chooser_controls(int x, int y, t_env *env)
{
	bg_paralax(x, y, env);
	check_back_button_select(x, y, env);
	if (env->menu->controls->pressed[4])
		move_scroller(y, env);
	draw_chooser(env);
}