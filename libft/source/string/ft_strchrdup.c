/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 01:54:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 03:56:15 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchrdup(char *str, char chr)
{
	long int	ct;
	long int	ct2;
	char		*new;

	ct = 0;
	ct2 = -1;
	while (str[ct] != chr && str[ct])
		ct++;
	new = ft_strnew(ct);
	while (++ct2 < ct)
		new[ct2] = str[ct2];
	return (new);
}
