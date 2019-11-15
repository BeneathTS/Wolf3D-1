/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_json_parse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 12:49:33 by sleonia           #+#    #+#             */
/*   Updated: 2019/11/12 18:03:50 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_JSON_PARSE_H
# define FT_JSON_PARSE_H
# include "libft.h"
# define KO_CODE		-1
# define OK_CODE		0

/*
**	Error`s
*/
# define READ_BIG_FILE_ERROR		"read_big_file error"
# define JSON_BASIC_VALIDATE_ERROR	"json_basic_validate error"
# define CUT_TRASH_C_ERROR			"cut_trash_c error"
# define FT_STRSPLIT_ERROR			"ft_strsplit error"
# define JSON_CAMERA_ERROR			"json-camera error"
# define JSON_LIGHTS_ERROR			"json-lights error"
# define JSON_FIGURES_ERROR			"json-figures error"

/*
**	field`s
*/
# define CAMERA_1		"\"camera\":"
# define LIGHTS_1		"\"lights\":"
# define FIGURES_1		"\"figures\":"

/*
**	Function`s and struct to some for parse json
*/

/*
**	json_cut_trash_c.c
*/
static int				json_word_count(const char *str, char *trash);
char					*json_cut_trash_c(char *json_file, short int key);

/*
**	json_basic_validate.c
*/
static void				json_init_variable(int *d_br, int *c_br,
							int *s_br, int flag);
static int				json_work_with_variable(int v_1, int v_2,
							int v_3, int flag);
int						json_basic_validate(char *json_file);

/*
**	json_primary_validate.c
*/
static int				json_is_field(char *json_file_line);
static int				json_is_name_object(char *json_file_line);
static int				json_is_array(char *json_file_line);
int						json_primary_validate(char **json_split);

/*
**	json_get_value_in_brackets.c
*/
static int				json_counter(int i, int count, char *input_str);
char					*json_get_value_in_brackets(char *input_str);

/*
**	json_array_parse.c
*/
static char				**json_get_array(const char *json_file_line);
static int				*json_int_array(const char *json_file_line);
static double			*json_double_array(const char *json_file_line);
void					*json_array_parse(int size,
							const char *json_file_line);

/*
**	json_find_in_file.c
*/
int						find_nbr_of_name(char **json_split, char *name);
int						find_nbr_of_line_in_obj(int start, int end,
							char **json_split, char *name);
int						find_nbr_of_line(char *name, char **json_split);
int						find_end_of_obj(char *name, char **json_split);

#endif
