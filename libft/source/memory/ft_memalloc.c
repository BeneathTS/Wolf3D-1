/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 07:29:30 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:50:44 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!(mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
