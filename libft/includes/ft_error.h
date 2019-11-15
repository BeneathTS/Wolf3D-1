/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:43 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/02 22:04:41 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include "libft.h"

/*
**	Library for return special value and print errors
*/

void		void_error(char *error_text);
void		*malloc_error();
int			int_error(char *error_text);
void		*char_error(char *error_text, char *line_for_free);
void		ft_exit(char *error_text);

#endif
