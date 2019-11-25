#include "wolf3d.h"

static void clear_maps(t_lvl_crd *cards, t_menu *menu, t_env *env)
{
	while (cards->id != 0)
		cards = cards->prev;
	while (1)
	{
		cards->id = 0;
		cards->pos = 0;
		cards->font_color = 0x0;
		free(cards->level_name);
		mlx_destroy_image(env->mlx, cards->background->tex_ptr);
		cards->background->tex_ptr = NULL;
		free(cards->background);
		cards->background = NULL;
		cards->level_name = NULL;
		if (cards->next)
		{
			cards = cards->next;
			free(cards->prev);
			cards->prev = NULL;
		}
		else
		{
			cards->prev = NULL;
			free(env->menu->cards);
			env->menu->cards = NULL;
			break ;
		}
	}
}

void draw_add_buttons(t_env *env)
{
	if (env->menu->sel_button == 'b')
		mlx_put_image_to_window(env->mlx, env->win, env->menu->back_button->prev->tex_ptr, WIDTH - 284, HEIGHT - 104); //134
	else
		mlx_put_image_to_window(env->mlx, env->win, env->menu->back_button->tex_ptr, WIDTH - 284, HEIGHT - 104);
	if (env->mode == Choose)
	{
		if (env->menu->sel_button == 'r')
			mlx_put_image_to_window(env->mlx, env->win, env->menu->refresh_button->prev->tex_ptr, WIDTH - 184, HEIGHT - 104);
		else
			mlx_put_image_to_window(env->mlx, env->win, env->menu->refresh_button->tex_ptr, WIDTH - 184, HEIGHT - 104);
	}
}

void check_push_add_buttons(int x, int y, t_env *env)
{
	if (x >= (WIDTH - 284) && x <= (WIDTH - 221) && y >= (HEIGHT - 104) && y <= (HEIGHT - 81))
	{
		env->mode = Menu;
		env->menu->controls->s_pos = 79;
		draw_main_menu(env);
	}
	if (x >= (WIDTH - 184) && x <= (WIDTH - 80) && y >= (HEIGHT - 104) && y <= (HEIGHT - 81))
	{
		env->menu->controls->s_pos = 79;
		clear_maps(env->menu->cards, env->menu, env);
		read_map_files(env);
		draw_chooser(env);
	}
}

void check_back_button_select(int x, int y, t_env *env)
{
	if (x >= (WIDTH - 284) && x <= (WIDTH - 221) && y >= (HEIGHT - 104) && y <= (HEIGHT - 81))
		env->menu->sel_button = 'b';
	else if (x >= (WIDTH - 184) && x <= (WIDTH - 80) && y >= (HEIGHT - 104) && y <= (HEIGHT - 81))
		env->menu->sel_button = 'r';
	else 
		env->menu->sel_button = 0;
}