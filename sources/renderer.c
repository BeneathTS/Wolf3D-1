/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:33:01 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/04 22:17:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Function that draw the floor.
**
** Function struct:
** 1. Fill the bottom half of the screen with color.
*/

static void		draw_ceiling(t_env *env)
{
	int			ct;
	int			finish;
	int			ct2;
	int			img_crd;

	ct = -1;
	finish = ((HEIGHT >> 1)) - env->cam->view_height * 0.5;
	while (++ct < finish)
	{
		ct2 = -1;
		while (++ct2 < WIDTH)
		{
			img_crd = ct * WIDTH + ct2;
			if (img_crd < WIDTH * HEIGHT && img_crd > -1)
				((int *)env->data_addr)[img_crd] = CEILING_COLOR;
		}
	}
}

static void		draw_floor(t_env *env)
{
	int			ct;
	int			ct2;
	int			img_crd;

	ct = (HEIGHT >> 1) - (env->cam->view_height >> 1) - 1;
	while (++ct < HEIGHT)
	{
		ct2 = -1;
		while (++ct2 < WIDTH)
		{
			img_crd = ct * WIDTH + ct2;
			if (img_crd < WIDTH * HEIGHT && img_crd > -1)
				((int *)env->data_addr)[img_crd] = FLOOR_COLOR;
		}
	}
}

/*
** Function that searches for texture color.
**
** Function struct:
** 1. Find texture in buffer by special id.
** 2. Return the texture color, located on tex_x(x) and tex_y(y) in buffer.
*/

static int		get_color(char tex_id, int tex_x, int tex_y, t_env *env)
{
	int			color;
	char		side;
	t_tex		*tmp;

	side = env->cast->ray->side;
	tmp = env->tex;
	if (tex_id == T_38)
	{
		if (side == H && env->cam->pos[X] > env->cast->ray->m_pos[X])
			tex_id = 85;
		else if (side == H && env->cam->pos[X] < env->cast->ray->m_pos[X])
			tex_id = 86;
		else if (side == V && env->cam->pos[Y] < env->cast->ray->m_pos[Y])
			tex_id = 87;
		else if (side == V && env->cam->pos[Y] > env->cast->ray->m_pos[Y])
			tex_id = 88;
	}
	while (tmp->id != tex_id)
	{
		tmp = tmp->next;
		if (!tmp)
			ft_exit(ERROR_MSG);
	}
	color = ((int *)tmp->data)[tex_x + tex_y * tmp->width];
	return (color);
}

/*
** Function that drawing columns for each x screen coordinates.
**
** Function struct:
** 1. Get the id of the texture.
** 2. Set start y position.
** 3. Set finish y position.
** 4. Get where the ray hits the wall.
** 5. Get where the ray hits the wall on x coordinate.
** 6. Get x texture coordinate. (that constant value)
** 7. Draw the column:
**   7.1 Get y texture coordinate.
**   7.2 Get texture color.
**   7.3 Put it on rendering image.
*/

static void		draw_column(t_cast *cast, t_env *env, t_cam *cam, const int x)
{
	t_draw_column	vars;

	vars.tex_id = env->map->level[cast->ray->m_pos[Y]][cast->ray->m_pos[X]];
	if ((vars.y[START] = ((HEIGHT - cam->view_height) >> 1) -
		(cast->wall_height >> 1) - 1) < -1)
		vars.y[START] = -1;
	if ((vars.y[FINISH] = ((HEIGHT - cam->view_height) >> 1) +
		(cast->wall_height >> 1)) >= HEIGHT)
		vars.y[FINISH] = HEIGHT - 1;
	vars.wall_x = (cast->ray->side == H
		? cam->pos[Y] + cast->distance * cast->ray->v_dir[Y]
		: cam->pos[X] + cast->distance * cast->ray->v_dir[X]);
	vars.wall_x -= floor(vars.wall_x);
	vars.tex_coord[X] = (int)(vars.wall_x * TEX_SIZE);
	while (++vars.y[START] < vars.y[FINISH])
	{
		vars.d = (vars.y[START] << 8) -
			((HEIGHT - cam->view_height - 1) << 7) + (cast->wall_height << 7);
		vars.tex_coord[Y] = ((vars.d * TEX_SIZE) / cast->wall_height) >> 8;
		((int *)env->data_addr)[vars.y[START] * WIDTH + x] =
			get_color(vars.tex_id, vars.tex_coord[X], vars.tex_coord[Y], env);
	}
}

/*
** 2.5D rendering function.
**
** Function struct:
** 1. Clear window. (cause we call this function more than once)
** 2. Draw the floor.
** 3. Cast a rays:
**   3.1 Cast a ray for each x coordinate.
** 	 3.2 Draw the screen column. (for each x screen coordinate)
** 4. Drop the rendered image on window.
**
** How it works:
** To draw the walls, we need to cast a rays for
**	each x coordinate of the window screen.
**
** The first thing we need to do is get the direction of the ray.
** Then, cast a ray to determine if there are walls in its way.
** After that, draw a column using the information received.
*/

void			renderer(t_env *env)
{
	int			ray;
	double		x;

	ft_bzero(env->data_addr, (WIDTH * (env->bts_pr_px >> 3)) * HEIGHT);
	mlx_clear_window(env->mlx, env->win);
	ray = -1;
	draw_floor(env);
	draw_ceiling(env);
	while (++ray < WIDTH)
	{
		x = 2 * ray / (double)WIDTH - 1;
		env->cast->ray->v_dir[X] = env->cam->c_v_dir[X]
			+ env->cam->c_v_plane[X] * x;
		env->cast->ray->v_dir[Y] = env->cam->c_v_dir[Y]
			+ env->cam->c_v_plane[Y] * x;
		cast_a_ray(env->cast, env->cam, env);
		draw_column(env->cast, env, env->cam, ray);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win,
		env->cam->weapon->tex_ptr, 420, 0);
}
