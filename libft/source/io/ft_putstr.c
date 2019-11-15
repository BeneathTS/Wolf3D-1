/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:17:43 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:49:29 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putstr(char const *s)
{
	char *str;

	str = (char *)s;
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}
