#include "wolf3d.h"

static void set_values(t_cast *cast, t_cam *cam, int *wall_hit)
{
	*wall_hit = NO;

	cast->distance = 0;

	cast->ray->m_pos[X] = (int)cam->pos[X];
	cast->ray->m_pos[Y] = (int)cam->pos[Y];

	cast->ray->d_dist[V] = sqrt(pow(cast->ray->v_dir[Y], 2.0) / 
	pow(cast->ray->v_dir[X], 2.0) + 1);

	cast->ray->d_dist[H] = sqrt(pow(cast->ray->v_dir[X], 2.0) / 
	pow(cast->ray->v_dir[Y], 2.0) + 1);

	cast->step[X] = (cast->ray->v_dir[X] > 0 ? 1 : -1);
	cast->step[Y] = (cast->ray->v_dir[Y] > 0 ? 1 : -1);

	cast->ray->s_dist[V] = (cast->step[X] > 0 ? cast->ray->m_pos[X] - cam->pos[X] + 1 : 
	cam->pos[X] - cast->ray->m_pos[X]) 
	* cast->ray->d_dist[V];
	
	cast->ray->s_dist[H] = (cast->step[Y] > 0 ? cast->ray->m_pos[Y] - cam->pos[Y] + 1 : 
	cam->pos[Y] - cast->ray->m_pos[Y]) 
	* cast->ray->d_dist[H];
}

static void wall_search(t_cast *cast, t_env *env, int *wall_hit)
{
	while (*wall_hit == NO)
	{

		if (cast->ray->s_dist[V] < cast->ray->s_dist[H])
		{
			cast->ray->s_dist[V] += cast->ray->d_dist[V];
			cast->ray->m_pos[X] += cast->step[X];
			cast->ray->side = V;
		}
		else
		{
			cast->ray->s_dist[H] += cast->ray->d_dist[H];
			cast->ray->m_pos[Y] += cast->step[Y];
			cast->ray->side = H;
		}
		if (env->map->level[env->cast->ray->m_pos[Y]][env->cast->ray->m_pos[X]] > '0')
			*wall_hit = YES;
	}
}

void cast_a_ray(t_cast *cast, t_cam *cam, t_env *env)
{
	int	wall_hit;

	set_values(cast, cam, &wall_hit);
	wall_search(cast, env, &wall_hit);
	if (wall_hit == YES)
	{
		cast->distance = (cast->ray->side == V ? (cast->ray->m_pos[X] - cam->pos[X] +
		(1 - cast->step[X]) / 2) / cast->ray->v_dir[X]
		: (cast->ray->m_pos[Y] - cam->pos[Y] +
		(1 - cast->step[Y]) / 2) / cast->ray->v_dir[Y]);

		cast->wall_height = (int)floor(HEIGHT * 1.27 / cast->distance);

		if ((cast->d_start = -cast->wall_height / 2 + HEIGHT / 2) < 0)
			cast->d_start = 0;
		if ((cast->d_end = cast->wall_height / 2 + HEIGHT / 2) >= HEIGHT)
			cast->d_end = HEIGHT - 1;
	}
}	