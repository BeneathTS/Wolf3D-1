#include "wolf3d.h"

void renderer(t_env *env)
{
	int x;

	x = -1;
	ft_bzero(env->data_addr, (WIDTH * env->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(env->mlx, env->win);
	while(++x < WIDTH)
	{
		cast_a_ray(env);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}