/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_symb_in_str_arr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:55:19 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/17 04:12:14 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_find_symb_in_str_arr(char **arr, char symbol)
{
	int		i;
	int		k;

	i = -1;
	while (arr[++i])
	{
		k = -1;
		while (arr[i][++k])
		{
			if (symbol == arr[i][k])
				return (1);
		}
	}
	return (0);
}
