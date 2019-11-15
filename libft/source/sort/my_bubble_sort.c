/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:15:30 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:52:34 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	How does it work?
**	We run and if see the value on
**	the left less than the right, we change them.
**	It works n^2 number of times
*/
#include "ft_sort.h"

int			*my_bubble_sort(int *array, int size)
{
	int		i;
	int		k;
	int		tmp;

	i = 0;
	k = 0;
	while (i++ < size - 1)
	{
		while (k++ < size - 1)
		{
			if (array[k] > array[k + 1])
			{
				tmp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = tmp;
			}
		}
	}
	return (array);
}
