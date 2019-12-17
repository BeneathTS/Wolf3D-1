/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:35 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/17 12:36:51 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1)
		ft_exit(ERROR_INPUT);
	env = env_init();
	load_menu_data(env);
	load_settings_data(env);
	load_chooser_data(env);
	load_weapon_texture(env);
	// change_music(music_flag_0, env->music);
	draw_main_menu(env);
	init_key_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
