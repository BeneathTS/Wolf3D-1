/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_string_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:38:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:50:41 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void		ft_destroy_string_arr(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		;
	while (--i >= 0)
		free(arr[i]);
	free(arr);
	arr = NULL;
}
