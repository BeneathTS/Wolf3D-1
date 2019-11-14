#include "wolf3d.h"

t_menu *menu_data_init()
{
	t_menu *menu;

	if (!(menu = (t_menu *)malloc(sizeof(t_menu))))
		exit(-1);
	menu->bg_off[X] = -93;
	menu->bg_off[Y] = -63;
	menu->tex = tex_init(NULL, NULL);
	return (menu);
}

t_cntrls *cntrls_init()
{
	t_cntrls *cntrls;

	if (!(cntrls = (t_cntrls *)malloc(sizeof(t_cntrls))))
		exit(-1);
	cntrls->angle = 0.0;
	cntrls->old_coord[X] = 0;
	cntrls->old_coord[Y] = 0;
	return (cntrls);
}

t_env		*env_init(t_map *map)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		exit (-1);
	env->map = map;
	env->tex = NULL;
	env->cam = cam_init();
	env->cast = cast_init();
	env->menu = menu_data_init();
	env->cntrls = cntrls_init();
	env->mode = MENU;
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