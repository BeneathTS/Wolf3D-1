/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 03:45:23 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 03:48:05 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_safe_malloc(size_t size)
{
	void *mem;

	if (!(mem = (void *)malloc(sizeof(void) * size)))
		ft_exit(ERROR_MALLOC);
	return (mem);
}
