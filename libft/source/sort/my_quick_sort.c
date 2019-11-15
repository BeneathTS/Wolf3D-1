/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:15:39 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:52:47 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	How does this work?
**	Select the middle element and start sorting.
**	After comparing and moving, we have 2 parts.
**	Less than the average element is bigger.
**	The middle element is selected in each of the parts and so on.
**	https://medium.com/karuna-sehgal/a-quick-explanation-of
**	-quick-sort-7d8e2563629b
*/

#include "ft_sort.h"

void		swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int			partition(int arr[], int left, int right)
{
	int		i;
	int		k;
	int		pivot;

	pivot = arr[right];
	i = (left - 1);
	k = left;
	while (k <= right - 1)
	{
		if (arr[k] < pivot)
		{
			i++;
			swap(&arr[i], &arr[k]);
		}
		++k;
	}
	swap(&arr[i + 1], &arr[right]);
	return (i + 1);
}

void		my_quick_sort(int arr[], int left, int right)
{
	int		p;

	if (left < right)
	{
		p = partition(arr, left, right);
		my_quick_sort(arr, left, p - 1);
		my_quick_sort(arr, p + 1, right);
	}
}
