/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:35 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/03 16:29:19 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_env	*env;
	t_map	*map;

	if (argc > 1)
		ft_exit(ERROR_INPUT);
	map = map_init();
	// if (!read_map(argv[1], map))
	// 	return (int_error("Error input!"));
	env = env_init(map);
	// load_textures(env);
	load_menu_data(env);
	load_settings_data(env);
	load_chooser_data(env);
	load_weapon_texture(env);
	//change_music(music_flag_0, env->music);
	draw_main_menu(env);
	init_key_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
