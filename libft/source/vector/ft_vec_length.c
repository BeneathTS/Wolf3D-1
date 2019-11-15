/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:40:09 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 12:48:00 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double		ft_vec_length(t_vector a)
{
	double	len;

	len = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	return (len);
}
