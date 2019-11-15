/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_find_in_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:35:28 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:50:08 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_json_parse.h"

int					find_nbr_of_name(char **json_split, char *name)
{
	int				i;

	i = -1;
	while (json_split[++i])
	{
		if (ft_strcmp(json_split[i], name) == 0)
			return (i);
	}
	return (KO_CODE);
}

int					find_nbr_of_line_in_obj(int start, int end,
						char **json_split, char *name)
{
	int				i;

	i = start;
	while (++i < end)
	{
		if (ft_strstr(json_split[i], name) != NULL)
			return (i);
	}
	return (KO_CODE);
}

int					find_nbr_of_line(char *name, char **json_split)
{
	int				i;

	i = 0;
	while (json_split[i])
	{
		if (ft_strstr(json_split[i], name) != NULL)
			return (i);
		i++;
	}
	return (KO_CODE);
}

int					find_end_of_obj(char *name, char **json_split)
{
	int				i;
	int				count_prnths;

	i = find_nbr_of_line(name, json_split);
	count_prnths = 0;
	while (json_split[++i])
	{
		if (ft_strstr(json_split[i], "{"))
			++count_prnths;
		else if (ft_strstr(json_split[i], "}"))
			--count_prnths;
		if (count_prnths == 0)
			break ;
	}
	return (i);
}
