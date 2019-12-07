/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:35 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/06 23:25:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_env	*env;
	t_map	*map;

	if (argc > 2)
		ft_exit(ERROR_INPUT);
	map = map_init();
	env = env_init(map);
	load_menu_data(env);
	load_settings_data(env);
	load_chooser_data(env);
	load_weapon_texture(env);
	change_music(music_flag_0, env->music);
	// draw_main_menu(env);

	read_map(argv[1], env->map);
	load_textures(env);

	renderer(env);
	init_key_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
