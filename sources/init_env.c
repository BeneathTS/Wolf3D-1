#include "wolf3d.h"

static void draw_scroll_base(t_menu *menu)
{
	int y;
	int finish;

	y = -1;
	finish = 645;
	while (++y < finish)
		((int *)menu->scroll->img_data)[y] = 0xCDFFFFFF;
}

t_menu *menu_data_init(t_env *env)
{
	t_menu *menu;

	if (!(menu = (t_menu *)malloc(sizeof(t_menu))))
		exit(-1);
	menu->bg_off[X] = -93;
	menu->bg_off[Y] = -63;
	menu->tex = tex_init(NULL, NULL);
	(void)env;
	if (!(menu->scroll = (t_scroll *)malloc(sizeof(t_scroll))))
		exit(-1);

	menu->scroll->img_ptr = mlx_new_image(env->mlx, 1, 645);
	menu->scroll->img_data = mlx_get_data_addr(menu->scroll->img_ptr, &menu->scroll->bts_pr_pxl, &menu->scroll->sz_ln, &menu->scroll->endian);
	menu->scroll->offset = 0;
	draw_scroll_base(menu);
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
	env->menu = menu_data_init(env);
	return (env);
}