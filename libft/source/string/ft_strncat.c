/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:34:17 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:25 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t len_dst;
	size_t i;

	i = 0;
	len_dst = ft_strlen(dst);
	while (src[i] && i < len)
	{
		dst[len_dst++] = src[i++];
	}
	dst[len_dst] = '\0';
	return (dst);
}
