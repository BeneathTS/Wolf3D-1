/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:06:29 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 04:15:20 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strup(char *s)
{
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	i = -1;
	str = (char *)ft_safe_malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[++i])
	{
		while (s[i] && s[i] >= 97 && s[i] <= 122)
		{
			str[i] = s[i] - 32;
			++i;
			if (!s[i])
			{
				str[i] = '\0';
				return (str);
			}
		}
		str[i] = s[i];
	}
	str[i] = '\0';
	return (str);
}
