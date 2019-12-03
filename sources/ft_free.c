/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:37:22 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/03 12:37:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

bool			ft_free(char **var_1, char **var_2)
{
	ft_destroy_string_arr(var_1);
	ft_destroy_string_arr(var_2);
	return (false);
}
