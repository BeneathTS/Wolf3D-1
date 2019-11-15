/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:17:19 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 01:59:35 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	ct;

	ct = -1;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		while (++ct < len)
			*(((unsigned char*)dst) + ct) = *(((unsigned char*)src) + ct);
	else
		while (len--)
			*(((unsigned char*)dst) + len) = *(((unsigned char*)src) + len);
	return (dst);
}
