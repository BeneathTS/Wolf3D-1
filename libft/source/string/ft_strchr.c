/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:02:36 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 02:00:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *str, int sym)
{
	int i;

	i = -1;
	while (*(str + (++i)))
		if (*(str + i) == sym)
			return (((char*)str) + i);
	if (sym == '\0')
		return (((char*)str) + i);
	return (0);
}
