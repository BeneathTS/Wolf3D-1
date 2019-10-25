#include "wolf3d.h"

void cast_a_ray(t_env *env)
{
	(void)env;

	double c;

	int mapX;
	int mapY;
	c = 0;
	while (c < 5)
	{
		mapX = (int)(env->cam->x / 64) + c*cos(env->cast->ray->angle);
		mapY = (int)(env->cam->y / 64) + c*sin(env->cast->ray->angle);
		c += 0.5;
		printf("%d %d\n", mapX, mapY);
		if (env->map->level[mapY][mapX] == '#')
		{
			printf("wall!\n");
			env->cast->distance = fabs(env->cam->x - mapX * 64);
			break;
		}
		//draw_pow(env, mapX, mapY);
	}
	draw_pow(env, mapX, mapY);
}	