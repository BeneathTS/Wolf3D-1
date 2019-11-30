#include "wolf3d.h"

void resset_card_coords(t_env *env)
{
	while (env->menu->cards->id != 0)
		env->menu->cards = env->menu->cards->prev;
	env->menu->cards->pos = 79;
	while (env->menu->cards->id < env->menu->controls->num_of_cards)
	{
		if (!env->menu->cards->next)
			break;
		env->menu->cards = env->menu->cards->next;
		env->menu->cards->pos = env->menu->cards->prev->pos + 106;
	}
}

static void scrolling(int y, t_env *env, char sign, int old_value)
{
	while (env->menu->cards->id != 0)
		env->menu->cards = env->menu->cards->prev;
	while (env->menu->cards->id < env->menu->controls->num_of_cards)
	{
		if (sign == 0)
			env->menu->cards->pos -= (env->menu->controls->s_pos - old_value) * ceil(env->menu->controls->num_of_cards / 7);
		else if (sign == 1)
			env->menu->cards->pos += (old_value - env->menu->controls->s_pos) * ceil(env->menu->controls->num_of_cards / 7);
		if (!env->menu->cards->next)
			break;
		env->menu->cards = env->menu->cards->next;
	}
}

static void move_scroller(int y, t_env *env)
{
	int temp;
	char sign;

	temp = env->menu->controls->s_pos;
	env->menu->controls->s_pos = y - 30;
	if (temp < env->menu->controls->s_pos)
		sign = 1;
	else if (temp > env->menu->controls->s_pos)
		sign = 0;
	if (y < 79 + 30)
		env->menu->controls->s_pos = 79;
	if (y > 842 + 30)
		env->menu->controls->s_pos = 842;
	if (temp != env->menu->controls->s_pos)
		scrolling(y, env, sign, temp);
}

void push_scroller(int x, int y, t_env *env)
{
	check_push_add_buttons(x, y, env);
	if (x >= WIDTH - 100 && x <= WIDTH - 78 &&
		y >= env->menu->controls->s_pos && y <= env->menu->controls->s_pos + 73 
		&& env->menu->controls->scroller_status == 1)
		env->menu->controls->pressed[4] = Yes;
}

void chooser_controls(int x, int y, t_env *env)
{
	bg_paralax(x, y, env);
	check_back_button_select(x, y, env);
	if (env->menu->controls->pressed[4])
		move_scroller(y, env);
	draw_chooser(env);
}