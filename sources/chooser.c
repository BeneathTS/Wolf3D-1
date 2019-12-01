#include "wolf3d.h"

void draw_base_n_scroller(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->menu->chooser->tex_ptr, (WIDTH - 89), 79);
	mlx_put_image_to_window(env->mlx, env->win, env->menu->chooser->prev->tex_ptr, WIDTH - 100, env->menu->controls->s_pos);
}

void draw_cards(t_env *env)
{
	while (env->menu->cards->id != env->menu->controls->id_first_card)
		env->menu->cards = env->menu->cards->prev;
	while (1)
	{
		if (env->menu->cards->pos < HEIGHT)
		{
			mlx_put_image_to_window(env->mlx, env->win, env->menu->cards->background->tex_ptr, 243, env->menu->cards->pos);
			mlx_string_put(env->mlx, env->win, 258, env->menu->cards->pos + 23, env->menu->cards->font_color, env->menu->cards->level_name);
		}
		if (env->menu->cards->next)
			env->menu->cards = env->menu->cards->next;
		else 
			break;
	}
}

void draw_chooser(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);

	mlx_put_image_to_window(env->mlx, env->win, env->menu->first_tex[Menu]->tex_ptr, env->menu->bg_off[X], env->menu->bg_off[Y]);
	if (env->menu->controls->scroller_status)
		draw_base_n_scroller(env);
	if (env->menu->controls->num_of_cards > 0)
		draw_cards(env);
	draw_add_buttons(env);
}