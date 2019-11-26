/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:33:01 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/26 06:13:32 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define CAM env->cam
#define CAST env->cast
#define WALL_H cast->wall_height
#define VIEW_H CAM->view_height

/*
** Function that draw the floor.
**
** Function struct:
** 1. Fill the bottom half of the screen with color.
*/

static void		draw_flow(t_env *env)
{
	int			ct;
	int			finish;
	int			ct2;
	int			img_crd;

	ct = -1;
	finish = ((HEIGHT >> 1)) - VIEW_H * 0.5;
	while (++ct < finish)
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

static void		draw_floor(t_env *env)
{
	int			ct;
	int			ct2;
	int			img_crd;

	ct = (HEIGHT >> 1) - (VIEW_H >> 1) - 1;
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
	t_tex		*tmp;

	tmp = env->tex;
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

static void		draw_column(t_cast *cast, t_env *env, const int x)
{
	int			y[2];
	int			tex_coord[2];
	int			d;
	char		tex_id;
	double		wall_x;

	tex_id = env->map->level[CAST->ray->m_pos[Y]][CAST->ray->m_pos[X]];
	if ((y[START] = ((HEIGHT - VIEW_H) >> 1) - (WALL_H >> 1) - 1) < -1)
		y[START] = -1;
	if ((y[FINISH] = ((HEIGHT - VIEW_H) >> 1) + (WALL_H >> 1)) >= HEIGHT)
		y[FINISH] = HEIGHT - 1;
	wall_x = (cast->ray->side == H ? CAM->pos[Y] + cast->distance *
	cast->ray->v_dir[Y] : CAM->pos[X] + cast->distance * cast->ray->v_dir[X]);
	wall_x -= floor(wall_x);
	tex_coord[X] = (int)(wall_x * TEX_SIZE);
	while (++y[START] < y[FINISH])
	{
		d = (y[START] << 8) - ((HEIGHT - VIEW_H - 1) << 7) + (WALL_H << 7);
		tex_coord[Y] = ((d * TEX_SIZE) / WALL_H) >> 8;
		// ((int *)env->data_addr)[y[START] * WIDTH + x] = 0xFF | get_color( //experiment for fog
		// 	tex_id, tex_coord[X], tex_coord[Y], env);
		((int *)env->data_addr)[y[START] * WIDTH + x] = get_color(
			tex_id, tex_coord[X], tex_coord[Y], env);
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
	draw_flow(env);
	while (++ray < WIDTH)
	{
		x = 2 * ray / (double)WIDTH - 1;
		CAST->ray->v_dir[X] = CAM->c_v_dir[X]
			+ CAM->c_v_plane[X] * x;
		CAST->ray->v_dir[Y] = CAM->c_v_dir[Y]
			+ CAM->c_v_plane[Y] * x;
		cast_a_ray(CAST, CAM, env);
		draw_column(CAST, env, ray);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win, env->cam->weapon->tex_ptr, 420, 0);
}
