#include "wolf3d.h"

static void set_color_alpha(char *data, int width, int height, 
unsigned int alpha_value, unsigned int color)
{
	int x;
	int y;

	y = -1;
	(void)color;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
		if (((int *)data)[y * width + x] == color)
			((int *)data)[y * width + x] |= (alpha_value << 24);
	}
}

void load_weapon_texture(t_env *env)
{
	env->cam->weapon = tex_init(NULL, NULL);
	env->cam->weapon->tex_ptr = mlx_xpm_file_to_image(env->mlx, GUN_1, &env->cam->weapon->width, 
	&env->cam->weapon->height);
	env->cam->weapon->data = mlx_get_data_addr(env->cam->weapon->tex_ptr, &env->cam->weapon->bts_pr_px, 
	&env->cam->weapon->sz_ln, &env->cam->weapon->endian);
	set_color_alpha(env->cam->weapon->data, env->cam->weapon->width, env->cam->weapon->height, 0xFF, 0x980088);
	env->cam->weapon->id = '1';
}
