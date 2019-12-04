/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:37:22 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/04 20:48:43 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

bool			ft_free(char **var_1, char **var_2)
{
	ft_destroy_string_arr(var_1);
	ft_destroy_string_arr(var_2);
	return (false);
}

void			ft_free_tex(t_env *env)
{
	while (1 && env->tex)
	{
		if (env->tex->next)
		{
			env->tex = env->tex->next;
			free(env->tex->prev);
			env->tex->prev = NULL;
		}
		else
		{
			env->tex->prev = NULL;
			free(env->tex);
			env->tex = NULL;
			break ;
		}
	}
}
