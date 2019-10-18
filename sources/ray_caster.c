#include "wolf3d.h"

static void set_values(t_env *env)
{
	
}

static void search_wall(t_env *env, char *wall_hit)
{
	int check;
	int dist_check;

	dist_check = 0;
	while (!wall_hit && dist_check < env->cam->depth)
	{
	}
}

void cast_a_ray(t_env *env)
{
	char wall_hit;

	wall_hit = 0;
	set_values(env);
	search_wall(env, &wall_hit);
}