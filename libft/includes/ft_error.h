/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:48:43 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/24 23:06:46 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H
# include "libft.h"

/*
**	Library for return special value and print errors
*/
# define ERROR_MSG				"\033[31mError!\033[0m"
# define ERROR_INIT_SDL			"\033[31mFailed to init SDL\033[0m"
# define ERROR_INPUT			"\033[31mError input!\033[0m"
# define ERROR_SYMBOLS			"\033[31mError symbols!\033[0m"
# define ERROR_MALLOC			"\033[31mMalloc error!\033[0m"
# define ERROR_READ_BIG_FILE	"\033[31mRead big file error!\033[0m"
# define ERROR_STRSPLIT			"\033[31mStrsplit error!\033[0m"
# define ERROR_CAMERA			"\033[31mCamera error!\033[0m"
# define ERROR_LIGHTS			"\033[31mLights error!\033[0m"
# define ERROR_FIGURES			"\033[31mFigures error!\033[0m"


void		                    void_error(char *error_text);
void		                    *malloc_error();
int			                    int_error(char *error_text);
void		                    *char_error(char *error_text,
									char *line_for_free);
void		                    ft_exit(char *error_text);

#endif
