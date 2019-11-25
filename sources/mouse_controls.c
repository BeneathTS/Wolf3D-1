/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:32:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/23 18:27:43 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int push_buttons(int button, int x, int y, t_env *env)
{
	if (env->mode == Menu && button == 1)
		menu_push_buttons(x, y, env);
	if (env->mode == Settings && button == 1)
		settings_push_buttons(x, y, env);
	if (env->mode == Choose && button ==1)
		push_scroller(x, y, env); 
	return (0);
}