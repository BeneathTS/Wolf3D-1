/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:31 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/18 08:30:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		find_in_arr_text(int value, char *arr_id_tex)
{
	int			i;

	i = -1;
	if (!arr_id_tex[0])
		return (0);
	while (++i < NBR_TEXTURES)
	{
		if (arr_id_tex[i] == value)
			return (-1);
		if (!arr_id_tex[i])
			return (i);
	}
	return (-1);
}

static void		get_arr_text_id(char *arr_id_tex, t_env *env)
{
	int			i;
	int			id;
	int			k;

	i = -1;
	while (env->map->level[++i])
	{
		k = -1;
		while (env->map->level[i][++k])
		{
			if (env->map->level[i][k] != '0')
			{
				if ((id = find_in_arr_text((int)env->map->level[i][k],
					arr_id_tex)) != -1)
					arr_id_tex[id] = env->map->level[i][k];
			}
		}
	}
}

void			load_texture(char *arr_id_tex, t_env **env)
{
	int			i;
	char		*tex;
	t_tex		*temp;

	i = -1;
	(*env)->tex = tex_init(NULL, NULL);
	temp = (*env)->tex;
	while (arr_id_tex[++i])
	{
		if (!(tex = get_texture_name(i, arr_id_tex)))
			ft_exit(ERROR_MSG);
		if (!(temp->tex_ptr = mlx_xpm_file_to_image((*env)->mlx, tex,
			&temp->width, &temp->height)))
			ft_exit(ERROR_MSG);
		if (!(temp->data = mlx_get_data_addr(temp->tex_ptr, &temp->bts_pr_px,
			&temp->sz_ln, &temp->endian)))
			ft_exit(ERROR_MSG);
		temp->id = arr_id_tex[i];
		if (arr_id_tex[i + 1])
		{
			temp->next = tex_init(temp, NULL);
			temp = temp->next;
		}
	}
}

void			load_textures(t_env *env)
{
	char		*arr_id_tex;

	arr_id_tex = ft_strnew(NBR_TEXTURES);
	get_arr_text_id(arr_id_tex, env);
	load_texture(arr_id_tex, &env);
	ft_strdel(&arr_id_tex);
}
