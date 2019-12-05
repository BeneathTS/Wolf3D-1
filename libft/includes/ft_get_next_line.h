/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 01:50:20 by sleonia           #+#    #+#             */
/*   Updated: 2019/12/05 21:51:09 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 2

# define ERROR -1
# define SUCCESS 1
# define NOTHING_RD 0

typedef struct		s_gnl
{
	int				fd;
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	struct s_gnl	*prev;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
#endif
