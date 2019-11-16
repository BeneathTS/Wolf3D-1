/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:31:36 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 04:17:25 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	if (!s)
		return (NULL);
	i = -1;
	str = (char *)ft_safe_malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	while (++i < len)
		*(str + i) = *(s + start++);
	return (str);
}
