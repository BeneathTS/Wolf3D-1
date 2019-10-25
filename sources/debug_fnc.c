#include "wolf3d.h"

void draw_player(t_env *env)
{
	int map;

	map = ((((int)(env->cam->y/64) * 10) + 100) * WIDTH) + (((int)(env->cam->x / 64) + 50) * 10);
	((int *)env->data_addr)[map] = 0x00FF00;
}

void draw_pow(t_env *env, int mapX, int mapY)
{
	int map;

	map = (((mapY * 10) + 100) * WIDTH) + ((mapX + 50) * 10);
	((int *)env->data_addr)[map] = 0xFF00FF;
}

void draw_map(t_env *env)
{
	int map;
	int x;
	int y;

	y = -1;
	while (env->map->level[++y])
	{
		x = -1;
		while (env->map->level[y][++x])
		{
			if (env->map->level[y][x] == '#')
			{
				map = (((y * 10) + 100) * WIDTH) + ((x + 50) * 10);
				((int*)env->data_addr)[map] = 0xFFFFFF;
			}
		}
	}
}