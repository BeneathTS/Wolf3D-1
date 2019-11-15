/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 08:08:44 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 01:58:52 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == (size_t)-1)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (NULL == str)
		return (NULL);
	ft_memset(str, 0, (size + 1));
	return (str);
}
