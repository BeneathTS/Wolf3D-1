/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:38:12 by ahiroko           #+#    #+#             */
/*   Updated: 2019/12/15 05:06:12 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	change_bg_color(t_lvl_crd *card, unsigned int color)
{
	int x;
	int y;

	y = -1;
	if (!card)
		ft_exit(CHANGE_BG_COLOR);
	while (++y < 72)
	{
		x = -1;
		while (++x < 1324)
			((int *)card->background->data)[y * 1324 + x] = color;
	}
}

void		unselect_old(t_lvl_crd *cards)
{
	if (cards->next)
		cards = cards->next;
	else
		return ;
	while (1)
	{
		cards->selected = No;
		cards->font_color = 0x575757;
		change_bg_color(cards, 0x55B7B7B7);
		if (!cards->next || cards->pos == HEIGHT)
			return ;
		cards = cards->next;
	}
}

void		check_card_selection(int x, int y, t_env *env)
{
	while (env->menu->cards->id != 0)
		env->menu->cards = env->menu->cards->prev;
	while (env->menu->cards->pos + 72 < 0)
		env->menu->cards = env->menu->cards->next;
	while (1)
	{
		if (x >= 243 && x <= 1567 &&
			y >= env->menu->cards->pos && y <= env->menu->cards->pos + 72)
		{
			env->menu->cards->selected = Yes;
			env->menu->cards->font_color = 0x000000;
			change_bg_color(env->menu->cards, 0x00FFFFFF);
			unselect_old(env->menu->cards);
			break ;
		}
		env->menu->cards->selected = No;
		env->menu->cards->font_color = 0x575757;
		change_bg_color(env->menu->cards, 0x55B7B7B7);
		if (!env->menu->cards->next || env->menu->cards->pos == HEIGHT)
			break ;
		env->menu->cards = env->menu->cards->next;
	}
}

void		chooser_controls(int x, int y, t_env *env)
{
	bg_paralax(x, y, env);
	check_add_button_select(x, y, env);
	if (env->menu->controls->pressed[4])
		move_scroller(y, env);
	if (env->menu->controls->num_of_cards > 0)
		check_card_selection(x, y, env);
	draw_chooser(env);
}
