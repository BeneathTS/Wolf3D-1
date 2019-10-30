#include "wolf3d.h"

// static void draw_column(t_cast *cast, t_env *env, const int x)
// {
// 	int color;
// 	int map_crd;

// 	if (env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]] == '1')
// 		color = 0xFFFFFF;
// 	else if (env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]] == '2')
// 		color = 0xFFFF00;
// 	else if (env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]] == '3')
// 		color = 0xFF00FF;

// 	 while (cast->d_start < cast->d_end)
// 	 {
// 	 	map_crd = cast->d_start * WIDTH + x;
// 		((int*)env->data_addr)[map_crd] = color;
// 	 	cast->d_start++;
// 	}
// }


static void draw_floor(t_env *env)
{
	int ct;
	int ct2;
	int img_crd;

	ct = HEIGHT / 2 - 1;
	while(++ct < HEIGHT)
	{
		ct2 = -1;
		while (++ct2 < WIDTH)
		{
			img_crd = ct * WIDTH + ct2;
			((int *)env->data_addr)[img_crd] = 0x353c44;
		}
	}
}

static int get_color(char tex_id, int tex_x, int tex_y, t_env *env)
{
	int color;

	while (env->tex->id != tex_id)
	{
		if (tex_id > env->tex->id)
			env->tex = env->tex->next;
		else
			env->tex = env->tex->prev;
		if (!env->tex)
			exit(-1);
	}
	color = ((int *)env->tex->data)[tex_x + tex_y * env->tex->width];
	return (color);
}

static void draw_column(t_cast *cast, t_env *env, const int x)
{
	int tex_x;
	int tex_y;
	int d;
	char tex_id;
	double wall_x;

	tex_id = env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]];

	wall_x = (cast->ray->side == V ? env->cam->pos[Y] + env->cast->distance * env->cast->ray->v_dir[Y] : env->cam->pos[X] + env->cast->distance * env->cast->ray->v_dir[X]);
	wall_x -= (int)wall_x;

	tex_x = (int)(wall_x * (double)TEX_SIZE);

	if (cast->ray->side == V && cast->ray->v_dir[X] > 0)
		tex_x = (TEX_SIZE - 1) - tex_x;

	if (cast->ray->side == H && cast->ray->v_dir[Y] < 0)
		tex_x = (TEX_SIZE - 1) - tex_x;

	while (cast->d_start < cast->d_end)
	{
		d = cast->d_start * 256 - HEIGHT * 128 + cast->wall_height *128;
		tex_y = ((d * TEX_SIZE) /cast->wall_height) / 256;
		((int *)env->data_addr)[cast->d_start * WIDTH + x] = get_color(tex_id, tex_x, tex_y, env);
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
	draw_floor(env);
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