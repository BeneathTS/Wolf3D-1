#include "wolf3d.h"

void load_textures(t_env *env)
{
	t_tex *temp;
	
	env->tex = tex_init(NULL, NULL);
	env->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, BS_TEX, &env->tex->width, &env->tex->height);
	env->tex->data = mlx_get_data_addr(env->tex->tex_ptr, &env->tex->bts_pr_pxl, &env->tex->sz_ln, &env->tex->endian);
	env->tex->id = '1';

	if (env->tex->width  != TEX_SIZE || env->tex->height != TEX_SIZE)
		exit (-1);
	
	temp = env->tex;

	env->tex->next = tex_init(env->tex, NULL);
	env->tex = env->tex->next;
	env->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, WD_TEX, &env->tex->width, &env->tex->height);
	env->tex->data = mlx_get_data_addr(env->tex->tex_ptr, &env->tex->bts_pr_pxl, &env->tex->sz_ln, &env->tex->endian);
	env->tex->id = '2';

	if (env->tex->width != TEX_SIZE || env->tex->height != TEX_SIZE)
		exit(-1);
	
	env->tex = temp;

	//mlx_put_image_to_window(env->mlx, env->win, env->tex->tex_ptr, 0, 0);
	//mlx_put_image_to_window(env->mlx, env->win, env->tex->next->tex_ptr, 0, 64);
}