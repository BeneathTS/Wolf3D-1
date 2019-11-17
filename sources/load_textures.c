/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:31 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/17 20:16:10 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void load_textures(t_env *env)
{
	t_tex *temp;
	
	env->tex = tex_init(NULL, NULL);
	env->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, BS_TEX, &env->tex->width, &env->tex->height);
	env->tex->data = mlx_get_data_addr(env->tex->tex_ptr, &env->tex->bts_pr_px, &env->tex->sz_ln, &env->tex->endian);
	env->tex->id = '1';
	if (env->tex->width  != TEX_SIZE || env->tex->height != TEX_SIZE)
		ft_exit(ERROR_MSG);
	temp = env->tex;
	env->tex->next = tex_init(env->tex, NULL);
	env->tex = env->tex->next;
	env->tex->tex_ptr = mlx_xpm_file_to_image(env->mlx, WD_TEX, &env->tex->width, &env->tex->height);
	env->tex->data = mlx_get_data_addr(env->tex->tex_ptr, &env->tex->bts_pr_px, &env->tex->sz_ln, &env->tex->endian);
	env->tex->id = '2';
	if (env->tex->width != TEX_SIZE || env->tex->height != TEX_SIZE)
		ft_exit(ERROR_MSG);
	env->tex = temp;
}
