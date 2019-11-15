/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_get_value_in_brackets.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 09:27:58 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:50:12 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_json_parse.h"

static int		json_counter(int i, int count, char *input_str)
{
	while (count != 2)
	{
		if (input_str[++i] == '"')
			++count;
	}
	return (i);
}

char			*json_get_value_in_brackets(char *input_str)
{
	int			i;
	int			k;
	int			count;
	char		*str_for_return;

	if (!(str_for_return = (char *)malloc(sizeof(char)
		* (json_counter(-1, 0, input_str) + 1))))
		return (NULL);
	i = -1;
	k = -1;
	count = 0;
	while (count != 2)
	{
		if (input_str[++i] == '"')
			++count;
		else
			str_for_return[++k] = input_str[i];
	}
	str_for_return[++k] = '\0';
	return (str_for_return);
}
