/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_array_parse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 05:42:09 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 13:27:16 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_json_parse.h"

static char		**json_get_array(const char *json_file_line)
{
	int			i;
	int			k;
	char		*str_for_split;
	char		**result_of_split;

	i = -1;
	k = -1;
	while (json_file_line[++i] != '[')
		;
	if (!(str_for_split = (char *)malloc(sizeof(char)
		* (ft_strlen(json_file_line) - i + 1))))
		return (NULL);
	while (json_file_line[i++] != ']')
		str_for_split[++k] = json_file_line[i];
	str_for_split[k] = '\0';
	if (!(result_of_split = ft_strsplit(str_for_split, ',')))
	{
		ft_strdel(&str_for_split);
		return (NULL);
	}
	ft_strdel(&str_for_split);
	return (result_of_split);
}

static int		*json_int_array(const char *json_file_line)
{
	int			i;
	int			*array;

	return (NULL);
}

static double	*json_double_array(const char *json_file_line)
{
	int			i;
	double		*array;
	char		**result_of_split;

	i = -1;
	if (!(result_of_split = json_get_array(json_file_line)))
		return (NULL);
	if (!(array = (double *)malloc(sizeof(double)
		* ft_len_arr(result_of_split))))
		return (NULL);
	while (result_of_split[++i])
		array[i] = ft_atof(result_of_split[i]);
	ft_destroy_string_arr(result_of_split);
	return (array);
}

void			*json_array_parse(int size, const char *json_file_line)
{
	if (size == sizeof(int))
		return (json_int_array(json_file_line));
	else if (size == sizeof(double))
		return (json_double_array(json_file_line));
	return (NULL);
}
