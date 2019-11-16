/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 08:05:22 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/16 04:17:40 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

unsigned int		ft_countw_delim(char const *s, char delim)
{
	unsigned int	i;
	unsigned int	count;
	unsigned char	f_word;

	i = 0;
	f_word = 0;
	count = 0;
	if (s)
		while (s[i])
		{
			if (s[i] == delim || s[i] == 0)
				if (f_word)
					f_word = 0;
			if (s[i] != delim && s[i])
				if (!f_word)
				{
					count++;
					f_word = 1;
				}
			i++;
		}
	return (count);
}

static unsigned int	wordend(char const *s, char const c, unsigned int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char			**abort_split(char **tab)
{
	unsigned int i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = 0;
	return (tab);
}

static void			init(unsigned int *i, unsigned int *w, unsigned int *j)
{
	*i = 0;
	*w = 0;
	*j = 0;
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	tablen;
	unsigned int	i;
	unsigned int	w;
	unsigned int	j;
	char			**tab;

	init(&i, &w, &j);
	tab = 0;
	tablen = ft_countw_delim(s, c);
	if ((tab = (char **)ft_safe_malloc(sizeof(char *) * (tablen + 1))) != 0)
	{
		tab[tablen] = 0;
		while (w < tablen)
			if (s[i] == c)
				i++;
			else
			{
				j = wordend(s, c, i);
				if ((tab[w++] = ft_strsub(s, i, j - i)) == 0)
					return (abort_split(tab));
				i = j;
			}
	}
	return (tab);
}
