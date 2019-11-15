#include "wolf3d.h"

int main(int argc, char **argv)
{
	t_env *env;
	t_map *map;

	if (argc != 2)
		exit(0);
	
	map = map_init();
	read_map(argv[1], map);
	env = env_init(map);

	load_textures(env);
	load_menu_data(env);
	//draw_menu(env);
	renderer(env);

	init_key_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}