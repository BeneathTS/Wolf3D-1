#include "wolf3d.h"

int x_close(t_env *env)
{
	(void)env;
	exit (0);
}

static void change_pov(int key, t_env * env)
{
	if (key == 124) //right
		env->cam->pov += 0.05;
	else if (key == 123) //left
		env->cam->pov -= 0.05;
	if (env->cam->pov < 0)
		env->cam->pov = 360;
	renderer(env);
}

static void move(int key, t_env *env)
{
	if (key == 0) // a
		env->cam->x -= 10;
	if (key == 1) // s
		env->cam->y += 10;
	if (key == 2) //d
		env->cam->x += 10;
	if (key == 13) //w
		env->cam->y -= 10;
	if (env->cam->x < 64)
		env->cam->x = 1;
	if (env->cam->y < 64)
		env->cam->y = 1;
	if (env->cam->x > env->map->width * 64)
		env->cam->x = env->map->width - env->cam->x;
	if (env->cam->y > env->map->height * 64)
		env->cam->y = env->map->height - env->cam->y;
	renderer(env);
}

int key_controls(int key, t_env *env)
{
	if (key == 53)
		x_close(env);
	if (key == 123 || key == 124)
		change_pov(key, env);
	if (key == 0 || key == 1 || key == 2 || key == 13)
		move(key, env);
	return (0);
}

void init_key_hooks(t_env *env)
{
	mlx_hook(env->win, 17, 0, x_close, env);
	mlx_hook(env->win, 2, 0, key_controls, env);
}