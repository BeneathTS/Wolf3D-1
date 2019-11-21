/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_data_load.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:28:22 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/21 13:29:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#define SETTINGS env->menu->settings

static char	*get_image(int ct)
{
	if (ct == 0)
		return (RT_STTNG);
	if (ct == 1)
		return (VLM_STTNG);
	if (ct == 2)
		return (DPTH_STTNG);
	return (NULL);
}

static void	load_titles(t_env *env)
{
	int		ct;

	SETTINGS->tex_ptr = mlx_xpm_file_to_image(env->mlx, MV_STTNG,
		&SETTINGS->width, &SETTINGS->height);
	SETTINGS->data = mlx_get_data_addr(SETTINGS->tex_ptr,
		&SETTINGS->bts_pr_px, &SETTINGS->sz_ln, &SETTINGS->endian);
	SETTINGS->id = 'M';
	ct = -1;
	while (++ct < 3)
	{
		SETTINGS->next = tex_init(SETTINGS, NULL);
		SETTINGS = SETTINGS->next;
		SETTINGS->tex_ptr = mlx_xpm_file_to_image(env->mlx, get_image(ct),
			&SETTINGS->width, &SETTINGS->height);
		SETTINGS->data = mlx_get_data_addr(SETTINGS->tex_ptr,
			&SETTINGS->bts_pr_px, &SETTINGS->sz_ln, &SETTINGS->endian);
		if (ct == 0)
			SETTINGS->id = 'R';
		if (ct == 1)
			SETTINGS->id = 'V';
		if (ct == 2)
			SETTINGS->id = 'D';
	}
}

static void	generate_rollers_base(t_env *env)
{
	int		ct_y;
	int		ct_x;

	ct_y = -1;
	while (++ct_y < 2)
	{
		ct_x = -1;
		while (++ct_x < 400)
			((int *)SETTINGS->data)[ct_y * 400 + ct_x] = 0xCDFFFFFF;
	}
}

static void	load_rollers(t_env *env)
{
	int		ct;

	ct = -1;
	while (++ct < 4)
	{
		SETTINGS->next = tex_init(SETTINGS, NULL);
		SETTINGS = SETTINGS->next;
		SETTINGS->tex_ptr = mlx_xpm_file_to_image(env->mlx, CNTRL_RLLR,
			&SETTINGS->width, &SETTINGS->height);
		SETTINGS->data = mlx_get_data_addr(SETTINGS->tex_ptr,
			&SETTINGS->bts_pr_px, &SETTINGS->sz_ln, &SETTINGS->endian);
		SETTINGS->id = '1' + ct;
	}
	ct = -1;
	while (++ct < 4)
	{
		SETTINGS->next = tex_init(SETTINGS, NULL);
		SETTINGS = SETTINGS->next;
		SETTINGS->tex_ptr = mlx_new_image(env->mlx, 400, 2);
		SETTINGS->data = mlx_get_data_addr(SETTINGS->tex_ptr,
			&SETTINGS->bts_pr_px, &SETTINGS->sz_ln, &SETTINGS->endian);
		SETTINGS->id = '5' + ct;
		generate_rollers_base(env);
	}
}

void		load_settings_data(t_env *env)
{
	env->menu->first_tex[Settings] = SETTINGS;
	load_titles(env);
	load_rollers(env);
}
