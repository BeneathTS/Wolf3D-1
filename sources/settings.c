#include "wolf3d.h"

void draw_settings(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);

	mlx_put_image_to_window(env->mlx, env->win, env->menu->first->tex_ptr, env->menu->bg_off[X], env->menu->bg_off[Y]);
}