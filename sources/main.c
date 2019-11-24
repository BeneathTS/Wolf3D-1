/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:35 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/25 02:47:58 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_env	*env;
	t_map	*map;

	if (argc != 2)
		ft_exit(ERROR_INPUT);
	map = map_init();
	read_map(argv[1], map);
	env = env_init(map);
	load_textures(env);
	load_menu_data(env);
	load_settings_data(env);
	change_music(music_flag_0, env->music);
	draw_main_menu(env);
	init_key_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
