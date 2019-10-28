#include "wolf3d.h"

static void draw_column(t_cast *cast, t_env *env, const int x)
{
	int color;
	int map_crd;

	if (env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]] == '1')
		color = 0xFFFFFF;
	else if (env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]] == '2')
		color = 0xFFFF00;
	else if (env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]] == '3')
		color = 0xFF00FF;

	 while (cast->d_start < cast->d_end)
	 {
	 	map_crd = cast->d_start * WIDTH + x;
		((int*)env->data_addr)[map_crd] = color;
	 	cast->d_start++;
	}
}

/*
** 2.5D rendering function.
** How it works:
** blah blah blah
*/
void renderer(t_env *env)
{
	int ray;
	double	x;

	ft_bzero(env->data_addr, (WIDTH * env->bts_pr_pxl / 8) * HEIGHT);
	mlx_clear_window(env->mlx, env->win);
	ray = -1;
	while(++ray < WIDTH)
	{
		x = 2 * ray / (double)WIDTH - 1;
		env->cast->ray->v_dir[X] = env->cam->c_v_dir[X] + env->cam->c_v_plane[X] * x;
		env->cast->ray->v_dir[Y] = env->cam->c_v_dir[Y] + env->cam->c_v_plane[Y] * x;
		
		cast_a_ray(env->cast, env->cam, env);
		
		draw_column(env->cast, env, ray);
	}
	
	
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}