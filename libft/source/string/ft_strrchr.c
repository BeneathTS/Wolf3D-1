/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:17:14 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	symb;
	size_t			len;

	len = ft_strlen(s);
	symb = (unsigned char)c;
	while (len > 0 && s[len] != symb)
		len--;
	if (s[len] == symb)
		return ((char *)&s[len]);
	else
		return (NULL);
}
