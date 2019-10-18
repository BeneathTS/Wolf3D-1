#include "wolf3d.h"

t_env		*env_init(t_map *map)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		exit (-1);
	env->map = map;
	env->cam = cam_init();
	env->cast = cast_init();
	if (!(env->mlx = mlx_init()))
		exit(-1);
	if (!(env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, "Wolf3D")))
		exit(-1);
	if (!(env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT)))
		exit(-1);
	if (!(env->data_addr = mlx_get_data_addr(env->img, &env->bts_pr_pxl, &env->sz_ln, &env->endian)))
		exit(-1);
	return (env);
}