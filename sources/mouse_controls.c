/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/18 07:41:43 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int push_buttons(int button, int x, int y, t_env *env)
{
	if (env->mode == Menu && button == 1)
		menu_push_buttons(x, y, env);
	return (0);
}