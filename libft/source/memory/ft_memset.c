/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:39:57 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 02:03:14 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t ct;

	ct = 0;
	while (ct < len)
		*(((char*)b) + (ct++)) = (unsigned char)c;
	return (b);
}
