/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:49:39 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:49:32 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	print_arr_str(char **arr_str)
{
	int	i;

	i = -1;
	if (!arr_str || !*arr_str)
	{
		ft_putendl("NO ARRAY!");
		return ;
	}
	while (arr_str[++i])
		ft_putendl(arr_str[i]);
}
