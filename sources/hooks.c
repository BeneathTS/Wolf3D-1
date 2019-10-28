#include "wolf3d.h"

int x_close(t_env *env)
{
	(void)env;
	exit (0);
}

static void rotate(int key, t_env *env)
{
	if (key == KB_A)
		env->cntrls->angle -= 0.05;
	if (key == KB_D)
		env->cntrls->angle += 0.05;

	env->cam->c_v_dir[X] = env->cam->v_dir[X] * cos(env->cntrls->angle) - env->cam->v_dir[Y] * sin(env->cntrls->angle);
	env->cam->c_v_dir[Y] = env->cam->v_dir[X] * sin(env->cntrls->angle) + env->cam->v_dir[Y] * cos(env->cntrls->angle);

	env->cam->c_v_plane[X] = env->cam->v_plane[X] * cos(env->cntrls->angle) - env->cam->v_plane[Y] * sin(env->cntrls->angle);
	env->cam->c_v_plane[Y] = env->cam->v_plane[X] * sin(env->cntrls->angle) + env->cam->v_plane[Y] * cos(env->cntrls->angle);
	renderer(env);
}

static void move(int key, t_env *env)
{
	if (key == KB_W)
	{
		env->cam->pos[Y] += env->cam->c_v_dir[Y] * env->cam->speed;
		env->cam->pos[X] += env->cam->c_v_dir[X] * env->cam->speed;
	}
	if (key == KB_S)
	{
		env->cam->pos[X] -= env->cam->c_v_dir[X] * env->cam->speed;
		env->cam->pos[Y] -= env->cam->c_v_dir[Y] * env->cam->speed;
	}
	if (env->cam->pos[X] < (1.0 + env->cam->speed))
		env->cam->pos[X] = 1.0 + env->cam->speed;
	if (env->cam->pos[X] > env->map->width - (1.0 + env->cam->speed))
		env->cam->pos[X] = env->map->width - (1.0 + env->cam->speed);
	if (env->cam->pos[Y] < (1.0 + env->cam->speed))
		env->cam->pos[Y] = 1.0 + env->cam->speed;
	if (env->cam->pos[Y] > env->map->height - (1.0 + env->cam->speed))
		env->cam->pos[Y] = env->map->height - (1.0 + env->cam->speed);
	renderer(env);
}

int key_controls(int key, t_env *env)
{
	if (key == ESC)
		x_close(env);
	if (key == KB_A || key == KB_D)
		rotate(key, env);
	if (key == KB_W || key == KB_S)
		move(key, env);
	return (0);
}

void init_key_hooks(t_env *env)
{
	mlx_hook(env->win, 17, 0, x_close, env);
	mlx_hook(env->win, 2, 0, key_controls, env);
}