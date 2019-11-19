#include "wolf3d.h"

static char *get_image(int ct)
{
	if (ct == 0)
		return (RT_STTNG);
	if (ct == 1)
		return (VLM_STTNG);
	return (NULL);
}

static void load_titles(t_env *env)
{
	int ct;

	env->menu->settings->tex_ptr = mlx_xpm_file_to_image(env->mlx, MV_STTNG, &env->menu->settings->width, &env->menu->settings->height);
	env->menu->settings->data = mlx_get_data_addr(env->menu->settings->tex_ptr, &env->menu->settings->bts_pr_px, &env->menu->settings->sz_ln, &env->menu->settings->endian);
	env->menu->settings->id = 'M';
	ct = -1;
	while (++ ct < 2)
	{
		env->menu->settings->next = tex_init(env->menu->settings, NULL);
		env->menu->settings = env->menu->settings->next;
		env->menu->settings->tex_ptr = mlx_xpm_file_to_image(env->mlx, get_image(ct), &env->menu->settings->width, &env->menu->settings->height);
		env->menu->settings->data = mlx_get_data_addr(env->menu->settings->tex_ptr, &env->menu->settings->bts_pr_px, &env->menu->settings->sz_ln, &env->menu->settings->endian);
		env->menu->settings->id = 'R' + (ct * 4);
	}
}

static void generate_rollers_base(t_env *env)
{
	int ct_y;
	int ct_x;

	ct_y = -1;
	while (++ct_y < 2)
	{
		ct_x = -1;
		while (++ct_x < 400)
			((int *)env->menu->settings->data)[ct_y * 400 + ct_x] = 0xCDFFFFFF;
	}
}

static void load_rollers(t_env *env)
{
	int ct;

	ct = -1;
	while (++ct < 3)
	{
		env->menu->settings->next = tex_init(env->menu->settings, NULL);
		env->menu->settings = env->menu->settings->next;
		env->menu->settings->tex_ptr = mlx_xpm_file_to_image(env->mlx, CNTRL_RLLR, &env->menu->settings->width, &env->menu->settings->height);
		env->menu->settings->data = mlx_get_data_addr(env->menu->settings->tex_ptr, &env->menu->settings->bts_pr_px, &env->menu->settings->sz_ln, &env->menu->settings->endian);
		env->menu->settings->id = '1' + ct;
	}
	ct = -1;
	while (++ct < 3)
	{
		env->menu->settings->next = tex_init(env->menu->settings, NULL);
		env->menu->settings = env->menu->settings->next;
		env->menu->settings->tex_ptr = mlx_new_image(env->mlx, 400, 2);
		env->menu->settings->data = mlx_get_data_addr(env->menu->settings->tex_ptr, &env->menu->settings->bts_pr_px, &env->menu->settings->sz_ln, &env->menu->settings->endian);
		env->menu->settings->id = '4' + ct;
		generate_rollers_base(env);
	}
}

void load_settings_data(t_env *env)
{
	env->menu->first_tex[Settings] = env->menu->settings;
	load_titles(env);
	load_rollers(env);
}