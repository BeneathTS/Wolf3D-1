/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:44:57 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 13:19:48 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double			ft_vec_multiplication(t_vector a, t_vector b, double angle)
{
	double		result;
	double		len_a;
	double		len_b;

	len_a = ft_vec_length(a);
	len_b = ft_vec_length(b);
	result = len_a * len_b * cos(angle);
	return (result);
}
