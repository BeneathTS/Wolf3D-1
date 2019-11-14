#include "wolf3d.h"

void set_alpha(char *data, int width, int height, unsigned int alpha_value)
{
	int x;
	int y;

	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			((int *)data)[y * width + x] |= (alpha_value << 24);
	}
}

static void draw_buttons(t_env *env)
{
	if (env->menu->sel_button == '1' && env->menu->tex->id == '5')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 592, 243);
	else if (env->menu->tex->id == '1' && env->menu->sel_button != '1')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 592, 243);
	
	if (env->menu->sel_button == '2' && env->menu->tex->id == '6')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 633, 310);
	else if (env->menu->tex->id == '2' && env->menu->sel_button != '2')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 633, 310);

	if (env->menu->sel_button == '3' && env->menu->tex->id == '7')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 623, 376);
	else if (env->menu->tex->id == '3' && env->menu->sel_button != '3')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 623, 376);
	if (env->menu->sel_button == '4' && env->menu->tex->id == '8')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 563, 442);
	else if (env->menu->tex->id == '4' && env->menu->sel_button != '4')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 563, 442);
}

void draw_menu(t_env *env)
{
	ft_bzero(env->data_addr, (WIDTH * (env->bts_pr_pxl >> 3)) * HEIGHT);
	mlx_clear_window(env->mlx, env->win);

	env->menu->tex = env->menu->first;
	mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, env->menu->bg_off[X], env->menu->bg_off[Y]);
	while ((env->menu->tex = env->menu->tex->next))
	{
		if (env->menu->tex->id == 'L')
			mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 305, 194);
		if (env->menu->tex->id == 'W')
			mlx_put_image_to_window(env->mlx, env->win, env->menu->tex->tex_ptr, 364, 263);
		draw_buttons(env);
	}
}