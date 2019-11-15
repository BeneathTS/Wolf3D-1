/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 00:18:30 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:49:39 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void				putstr_color(char *color, char const *s)
{
	int				i;

	i = -1;
	if (ft_strcmp(color, "red") == 0)
		ft_putstr("\033[31m");
	if (ft_strcmp(color, "green") == 0)
		ft_putstr("\033[32m");
	if (ft_strcmp(color, "yellow") == 0)
		ft_putstr("\033[33m");
	if (ft_strcmp(color, "blue") == 0)
		ft_putstr("\033[34m");
	if (ft_strcmp(color, "pink") == 0)
		ft_putstr("\033[35m");
	if (ft_strcmp(color, "aqua") == 0)
		ft_putstr("\033[36m");
	if (s)
	{
		while (s[++i])
			write(1, &s[i], 1);
		write(1, "\n", 1);
	}
}
