/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 08:21:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/10 08:22:26 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

size_t			ft_strlen_without_symb(char symb, const char *s)
{
	size_t		i;
	size_t		count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] != symb)
			count++;
	}
	return (count);
}

char			*ft_strnew_without_symb(char symb, char *str)
{
	int			i;
	int			k;
	int			len;
	char		*new_str;

	len = ft_strlen_without_symb(' ', (const char *)str);
	new_str = ft_strnew(len);
	i = -1;
	k = -1;
	while (str[++i])
	{
		if (str[i] != symb)
			new_str[++k] = str[i];
	}
	return (new_str);
}
