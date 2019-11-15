#include "wolf3d.h"

// void get_scroller_position(int x, int y, t_env *env)
// {

// }

void draw_chooser(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);

	mlx_put_image_to_window(env->mlx, env->win, env->menu->first->tex_ptr, env->menu->bg_off[X], env->menu->bg_off[Y]);
	mlx_put_image_to_window(env->mlx, env->win, env->menu->scroll->img_ptr, 1181, 38);
	mlx_put_image_to_window(env->mlx, env->win, env->menu->chsr->tex_ptr, 1173, 48 + env->menu->scroll->offset);
}