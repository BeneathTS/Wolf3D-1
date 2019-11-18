/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 02:56:46 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/18 06:53:05 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char		*bad_guy_choise(int symbol)
{
	if (symbol == (char)T_1)
		return (BAD_GUY);
	else if (symbol == (char)T_2)
		return (BAD_GUY_2);
	else if (symbol == (char)T_3)
		return (DEAD_GUY);
	return (NULL);
}

static char		*wall_choise_3(int symbol)
{
	if (symbol == (char)T_32)
		return (WALL80);
	else if (symbol == (char)T_33)
		return (WALL81);
	else if (symbol == (char)T_34)
		return (WALL85);
	else if (symbol == (char)T_35)
		return (WALL89);
	else if (symbol == (char)T_36)
		return (WALL92);
	else if (symbol == (char)T_37)
		return (WALL96);
	return (NULL);
}

static char		*wall_choise_2(int symbol)
{
	if (symbol == (char)T_21)
		return (WALL35);
	else if (symbol == (char)T_22)
		return (WALL40);
	else if (symbol == (char)T_23)
		return (WALL51);
	else if (symbol == (char)T_24)
		return (WALL55);
	else if (symbol == (char)T_25)
		return (WALL64);
	else if (symbol == (char)T_26)
		return (WALL71);
	else if (symbol == (char)T_27)
		return (WALL72);
	else if (symbol == (char)T_28)
		return (WALL74);
	else if (symbol == (char)T_29)
		return (WALL76);
	else if (symbol == (char)T_30)
		return (WALL77);
	else if (symbol == (char)T_31)
		return (WALL79);
	return (wall_choise_3(symbol));
}

static char		*wall_choise(int symbol)
{
	if (symbol == (char)T_10)
		return (WALL0);
	else if (symbol == (char)T_11)
		return (WALL3);
	else if (symbol == (char)T_12)
		return (WALL7);
	else if (symbol == (char)T_13)
		return (WALL10);
	else if (symbol == (char)T_14)
		return (WALL13);
	else if (symbol == (char)T_15)
		return (WALL14);
	else if (symbol == (char)T_16)
		return (WALL16);
	else if (symbol == (char)T_17)
		return (WALL18);
	else if (symbol == (char)T_18)
		return (WALL21);
	else if (symbol == (char)T_19)
		return (WALL32);
	else if (symbol == (char)T_20)
		return (WALL33);
	return (wall_choise_2(symbol));
}

char			*get_texture_name(int i, char *arr_id_tex)
{
	char		*res;

	res = NULL;
	if ((res = bad_guy_choise(arr_id_tex[i])))
		return (res);
	else if ((res = wall_choise(arr_id_tex[i])))
		return (res);
	return (NULL);
}
