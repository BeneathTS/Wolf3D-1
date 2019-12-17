/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_data_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 20:15:04 by ahiroko           #+#    #+#             */
/*   Updated: 2019/12/17 13:32:56 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char	*get_img(int ct)
{
	if (ct == 0)
		return (RT_STTNG);
	if (ct == 1)
		return (VLM_STTNG);
	if (ct == 2)
		return (DPTH_STTNG);
	return (NULL);
}

static void	load_titles(t_env *env) //sega?
{
	int i;

	if (!(env->menu->settings->tex_ptr = mlx_xpm_file_to_image(env->mlx,
	MV_STTNG, &env->menu->settings->width, &env->menu->settings->height)))
		ft_exit(LOAD_TITLES);
	env->menu->settings->data = mlx_get_data_addr(env->menu->settings->tex_ptr,
		&env->menu->settings->bts_pr_px, &env->menu->settings->sz_ln,
		&env->menu->settings->endian);
	env->menu->settings->id = 'M';
	i = -1;
	while (++i < 3)
	{
		env->menu->settings->next = tex_init(env->menu->settings, NULL);
		env->menu->settings = env->menu->settings->next;
		if (!(env->menu->settings->tex_ptr = mlx_xpm_file_to_image(env->mlx,
			get_img(i), &env->menu->settings->width,
			&env->menu->settings->height)))
			ft_exit(LOAD_TITLES);
		env->menu->settings->data = mlx_get_data_addr(
			env->menu->settings->tex_ptr, &env->menu->settings->bts_pr_px,
			&env->menu->settings->sz_ln, &env->menu->settings->endian);
		env->menu->settings->id = 'R' + 4 * i;
		if (i > 1)
			env->menu->settings->id = 'D';
	}
}

static void	create_rollers(t_env *env) //sega?
{
	int ct_y;
	int ct_x;

	if (!(env->menu->settings->tex_ptr = mlx_new_image(env->mlx, 400, 2)))
		ft_exit(CREATE_ROLLERS);
	env->menu->settings->data =
	mlx_get_data_addr(env->menu->settings->tex_ptr,
	&env->menu->settings->bts_pr_px, &env->menu->settings->sz_ln,
	&env->menu->settings->endian);
	ct_y = -1;
	while (++ct_y < 2)
	{
		ct_x = -1;
		while (++ct_x < 400)
			((int *)env->menu->settings->data)[ct_y * 400 + ct_x] = 0xCDFFFFFF;
	}
}

static void	load_rollers(t_env *env) //sega?
{
	int ct;

	ct = -1;
	while (++ct < 8)
	{
		env->menu->settings->next = tex_init(env->menu->settings, NULL);
		env->menu->settings = env->menu->settings->next;
		if (ct < 4)
		{
			if (!(env->menu->settings->tex_ptr =
			mlx_xpm_file_to_image(env->mlx,
			CNTRL_RLLR, &env->menu->settings->width,
			&env->menu->settings->height)))
				ft_exit(LOAD_ROLLERS);
			env->menu->settings->data =
			mlx_get_data_addr(env->menu->settings->tex_ptr,
			&env->menu->settings->bts_pr_px, &env->menu->settings->sz_ln,
			&env->menu->settings->endian);
		}
		else
			create_rollers(env);
		env->menu->settings->id = '1' + ct;
	}
}

void		load_settings_data(t_env *env)
{
	env->menu->first_tex[Settings] = env->menu->settings;
	load_titles(env);
	load_rollers(env);
}
