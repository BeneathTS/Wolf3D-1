/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:03:21 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hs = haystack;
	size_t		nd_len;

	nd_len = ft_strlen(needle);
	if (nd_len == 0)
		return ((char *)hs);
	while (len && *hs)
	{
		if (len >= nd_len)
			if (!(ft_strncmp(hs, needle, nd_len)))
				return ((char *)hs);
		hs++;
		len--;
	}
	return (0);
}
