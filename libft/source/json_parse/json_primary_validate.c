/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_primary_validate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 10:38:09 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 13:22:04 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_json_parse.h"

static int			json_is_name_object(char *json_file_line)
{
	int				i;
	int				len;
	int				count;

	i = -1;
	len = ft_strlen(json_file_line);
	count = 0;
	while (json_file_line[++i])
	{
		if (json_file_line[i] == '"')
			++count;
		if (count == 2 && json_file_line[len - 1] == ':')
			return (0);
	}
	return (1);
}

static int			json_is_field(char *json_file_line)
{
	int				i;
	int				cnt_1;
	int				cnt_2;

	i = -1;
	cnt_1 = 0;
	cnt_2 = 0;
	while (json_file_line[++i])
	{
		if (json_file_line[i] == '"')
			++cnt_1;
		if (json_file_line[i] == ':')
			++cnt_2;
	}
	return (cnt_1 == 4 && ft_strstr(json_file_line, "\":\"") && cnt_2 == 1);
}

static int			json_is_array(char *json_file_line)
{
	int				i;
	int				cnt_1;

	i = -1;
	cnt_1 = 0;
	while (json_file_line[++i])
	{
		if (json_file_line[i] == ':')
			++cnt_1;
	}
	return (ft_strstr(json_file_line, "\":[") && cnt_1 == 1);
}

int					json_primary_validate(char **json_split)
{
	int				i;

	i = -1;
	while (json_split[++i])
	{
		if (ft_strcmp(json_split[i], "{") == 0)
			continue ;
		else if (ft_strcmp(json_split[i], "}") == 0)
			continue ;
		else if (ft_strcmp(json_split[i], "},") == 0)
			continue ;
		else if (json_is_name_object(json_split[i]) == 0)
			continue ;
		else if (json_is_field(json_split[i]) == 0)
			continue;
		else if (json_is_array(json_split[i]) == 0)
			continue;
		else
			return (1);
	}
	return (0);
}
