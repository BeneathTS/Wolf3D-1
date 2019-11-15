/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_chooser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:31:41 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/15 23:56:43 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_chooser(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->menu->first->tex_ptr,
		env->menu->bg_off[X], env->menu->bg_off[Y]);
	mlx_put_image_to_window(env->mlx, env->win, env->menu->scroll->img_ptr,
		1181, 38);
	mlx_put_image_to_window(env->mlx, env->win, env->menu->chsr->tex_ptr, 1173,
		48 + env->menu->scroll->offset);
}
