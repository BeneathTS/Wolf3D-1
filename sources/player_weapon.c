/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:39:44 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/04 20:33:11 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			set_color_alpha(t_tex *w, int alpha_value, int color)
{
	int x;
	int y;

	y = -1;
	(void)color;
	while (++y < w->height)
	{
		x = -1;
		while (++x < w->width)
		{
			if (((int *)w->data)[y * w->width + x] == color)
				((int *)w->data)[y * w->width + x] |= (alpha_value << 24);
		}
	}
}

void				load_weapon_texture(t_env *env)
{
	env->cam->weapon = tex_init(NULL, NULL);
	if (!(env->cam->weapon->tex_ptr = mlx_xpm_file_to_image(env->mlx, GUN_1,
		&env->cam->weapon->width, &env->cam->weapon->height)))
		ft_exit(ERROR_MSG);
	env->cam->weapon->data = mlx_get_data_addr(
		env->cam->weapon->tex_ptr, &env->cam->weapon->bts_pr_px,
		&env->cam->weapon->sz_ln, &env->cam->weapon->endian);
	set_color_alpha(env->cam->weapon, 0xFF, 0x980088);
	env->cam->weapon->id = '1';
}
