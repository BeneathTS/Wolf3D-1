/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser_scroller_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 03:56:37 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/22 16:41:38 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	What's the logic here? The function will return the map as a structure
**		next you'll have to look at map->level.
**	if it is NULL:
** 		Then I start the reader
**	  if read_map return NULL
**		an alert is triggered
**	  else
**		i activate game mode
**	else
**		i activate game mode
*/

static void	activate_game_mode(t_env *env)
{
	env->menu->cards->selected = No;
	env->menu->cards->font_color = 0x575757;
	change_bg_color(env->menu->cards, 0x55B7B7B7);
	load_textures(env);
	env->mode = Game;
	change_music(music_flag_1, env->music);
	renderer(env);
}

void		check_validation(const char *map_loc, t_env *env)
{
	t_map	*tmp;

	if (!(tmp = find_current_map(map_loc, &env->map)))
		ft_exit(CHECK_VALIDATION);
	if (!tmp->level)
	{
		if (!read_map(map_loc, tmp))
		{
			playSound(CHOOSER_ERROR, 128);
			system("osascript -e \'display notification\" \
This map is not valid!\" with title \"Warning!\"\'");
		}
		else
			activate_game_mode(env);
	}
	else
		activate_game_mode(env);
}
