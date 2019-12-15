/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:31:36 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/15 01:49:31 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin_free(char *s1, char *s2, int num)
{
	size_t	ct;
	size_t	ct2;
	char	*nw;

	ct = -1;
	ct2 = ct;
	if (NULL == s2 || NULL == s1)
		return (NULL);
	nw = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (*(s1 + (++ct)))
		*(nw + ct) = *(s1 + ct);
	while (*(s2 + (++ct2)))
		*(nw + ct++) = *(s2 + ct2);
	if (num == 1)
		ft_strdel(&s1);
	else if (num == 2)
		ft_strdel(&s2);
	else if (num == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (nw);
}
