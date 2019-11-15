/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_basic_validate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 03:01:03 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:50:03 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_json_parse.h"

/*
**	If flag == 0 we json_init_variable()
**	If flag == 1 we nothing make
**	If flag == 2 we return double_brackets
**	If flag == 3 we return curly_brackets
**	If flag == 4 we return square_brackets
*/

static int			json_check_symb(int symb)
{
	if (symb == '"' || symb == '{' || symb == '}' || symb == '[' || symb == ']'
		|| symb == '\n' || symb == '\t' || symb == '\t' || symb == ','
		|| symb == '.' || symb == ':' || symb == '_' || symb == '-'
		|| symb == ' ' || ft_isalnum(symb) == 1 || ft_isalpha(symb) == 1)
		return (0);
	else
	{
		putstr_color("yellow", "You write on json: ");
		putchar_color("yellow", (char)symb);
		putstr_color("red", "You must use only this symbols on json file:\n\
1.  \\t\n\
2.  \\n\n\
3.  {}\n\
4.  []\n\
5.  -\n\
6.  _\n\
7.  \"\n\
8.  0-9\n\
9.  A-Z and a-z\n\
10. ,\n");
		return (1);
	}
	return (0);
}

static void			json_init_variable(int *d_br, int *c_br,
						int *s_br, int flag)
{
	*d_br = 0;
	*c_br = 0;
	*s_br = 0;
}

static int			json_work_with_variable(int v_1, int v_2,
						int v_3, int flag)
{
	static int		double_brackets;
	static int		curly_brackets;
	static int		square_brackets;

	if (flag == 0)
		json_init_variable(&double_brackets, &curly_brackets,
			&square_brackets, 0);
	else if (flag == 1)
	{
		double_brackets += v_1;
		curly_brackets += v_2;
		square_brackets += v_3;
	}
	else if (flag == 2)
		return (double_brackets);
	else if (flag == 3)
		return (curly_brackets);
	else if (flag == 4)
		return (square_brackets);
	return (0);
}

int					json_basic_validate(char *json_file)
{
	int				i;

	i = -1;
	while (json_file[++i])
	{
		if (json_check_symb(json_file[i]) == 1)
			return (1);
		else if (json_file[i] == '"' && json_file[i + 1] == '"')
			return (1);
		else if (json_file[i] == '"')
			json_work_with_variable(1, 0, 0, 1);
		else if (json_file[i] == '{' || json_file[i] == '}')
			json_work_with_variable(0, 1, 0, 1);
		else if (json_file[i] == '[' || json_file[i] == ']')
			json_work_with_variable(0, 0, 1, 1);
	}
	return ((json_work_with_variable(0, 0, 0, 2) % 2 == 0
			&& json_work_with_variable(0, 0, 0, 3) % 2 == 0
			&& json_work_with_variable(0, 0, 0, 4) % 2 == 0) ? 0 : 1);
}
