#include "wolf3d.h"

static void create_background(t_env *env, t_lvl_crd *card)
{
	int x;
	int y;

	y = -1;
	card->background = tex_init(NULL, NULL);
	card->background->tex_ptr = mlx_new_image(env->mlx, 1324, 72);
	card->background->data = mlx_get_data_addr(card->background->tex_ptr, &card->background->bts_pr_px, &card->background->sz_ln, &card->background->endian);
	while (++y < 72)
	{
		x = -1;
		while (++x < 1324)
			((int *)card->background->data)[y * 1324 + x] = 0x55B7B7B7;
	}
}

static t_lvl_crd *create_card(t_env *env, int id, const char *file_name, t_lvl_crd *prev)
{
	t_lvl_crd *new_card;

	if (!(new_card = (t_lvl_crd *)malloc(sizeof(t_lvl_crd))))
		ft_exit(ERROR_MSG);
	new_card->id = id;
	if (!(new_card->level_name = ft_strdup(file_name)))
		ft_exit(ERROR_MSG);
	if (prev)
	{
		if (prev->pos + 106 <= HEIGHT)
			new_card->pos = prev->pos + 106;
		else
			new_card->pos = HEIGHT;
	}
	else
		new_card->pos = 79;
	new_card->prev = prev;
	new_card->next = NULL;
	create_background(env, new_card);
	new_card->font_color = 0x575757;
	return (new_card);
}

void read_map_files(t_env *env)
{
	int ct;
	int len;
	int id;

	ct = -1;
	id = 0;
	if (!(env->menu->dir_ptr = opendir(MAPS_FOLDER)))
		ft_exit(ERROR_MSG);

	while (++ct < MAPS_LIMIT && (env->menu->file_name = readdir(env->menu->dir_ptr)))
	{
		len = ft_strlen(env->menu->file_name->d_name);
		if (env->menu->file_name->d_name[len - 3] == '.' &&
			env->menu->file_name->d_name[len - 2] == 'w' &&
			env->menu->file_name->d_name[len - 1] == 'm')
		{
			if (!env->menu->cards)
				env->menu->cards = create_card(env, id++, env->menu->file_name->d_name, env->menu->cards);
			else 
				env->menu->cards = (env->menu->cards->next = 
				create_card(env, id++, env->menu->file_name->d_name, env->menu->cards));
		}
	}
	env->menu->controls->num_of_cards = id + 1;
	closedir(env->menu->dir_ptr);
	env->menu->dir_ptr = NULL;
}

void load_scroller(t_env *env)
{
	int ct;

	ct = -1;
	env->menu->chooser->tex_ptr = mlx_xpm_file_to_image(env->mlx, SCRL, &env->menu->chooser->width, &env->menu->chooser->height);
	env->menu->chooser->data = mlx_get_data_addr(env->menu->chooser->tex_ptr, &env->menu->chooser->bts_pr_px, &env->menu->chooser->sz_ln, &env->menu->chooser->endian);
	env->menu->chooser->id = 'S';

	env->menu->chooser->next = tex_init(env->menu->chooser, NULL);
	env->menu->chooser = env->menu->chooser->next;
	env->menu->chooser->tex_ptr = mlx_new_image(env->mlx, 1, 835);
	env->menu->chooser->data = mlx_get_data_addr(env->menu->chooser->tex_ptr, &env->menu->chooser->bts_pr_px, &env->menu->chooser->sz_ln, &env->menu->chooser->endian);
	env->menu->chooser->id = 'B';
	while (++ct < 835)
		((int *)env->menu->chooser->data)[ct] = 0xCDFFFFFF;
}

void load_chooser_data(t_env *env)
{
	load_scroller(env);
	env->menu->controls->scroller_status = 1;
	env->menu->controls->id_first_card = 0;
	read_map_files(env);
}