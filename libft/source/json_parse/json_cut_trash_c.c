/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_cut_trash_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:56:56 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 13:26:06 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_json_parse.h"

static int			json_word_count(const char *json_file, char *trash)
{
	int				word;

	word = 0;
	if ((*json_file != trash[0] && *json_file != trash[1]) && *json_file)
	{
		json_file++;
		word++;
	}
	while (*json_file)
	{
		while (*json_file == trash[0] || *json_file == trash[1])
		{
			json_file++;
			if ((*json_file != trash[0] && *json_file != trash[1])
				&& *json_file)
				word++;
		}
		json_file++;
	}
	return (word);
}

static char			*json_create_array_of_trash(void)
{
	char			*trash;

	if (!(trash = (char *)malloc(sizeof(char) * 3)))
		return (NULL);
	trash[0] = ' ';
	trash[1] = '\t';
	trash[2] = '\0';
	return (trash);
}

char				*json_cut_trash_c(char *json_file, short int key)
{
	int				i;
	int				k;
	int				count;
	char			*trash;
	char			*new_str;

	i = 0;
	k = 0;
	if (!json_file || !(trash = json_create_array_of_trash()))
		return (NULL);
	count = (int)ft_strlen(json_file) - json_word_count(json_file, trash);
	if (!(new_str = (char *)ft_memalloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (json_file[i])
	{
		while ((json_file[i] == trash[0]
			|| json_file[i] == trash[1]) && json_file[i])
			i++;
		new_str[k] = json_file[i];
		k += 1;
		i += 1;
	}
	if (key == 0)
		ft_strdel(&json_file);
	return (new_str);
}
