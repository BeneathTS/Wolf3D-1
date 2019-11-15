/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_multiplication_num.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:41:06 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 16:48:12 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector		ft_vec_multiplication_num(t_vector a, double num)
{
	t_vector	b;

	b.x = a.x * num;
	b.y = a.y * num;
	b.z = a.z * num;
	return (b);
}
