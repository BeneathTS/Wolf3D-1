# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    json_parse.mk                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 13:10:47 by sleonia           #+#    #+#              #
#    Updated: 2019/11/12 13:46:18 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a
SRC_JSON_PARSE_PATH = ./source/json_parse/
OBJ_JSON_PARSE_PATH = ./objects/json_parse/
INC_PATH = ./includes/
SRC_JSON_PARSE = $(addprefix $(SRC_JSON_PARSE_PATH), $(SRC_JSON_PARSE_NAME))
OBJ_JSON_PARSE = $(addprefix $(OBJ_JSON_PARSE_PATH), $(OBJ_JSON_PARSE_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_JSON_PARSE_NAME = 	json_cut_trash_c.c	json_basic_validate.c	json_primary_validate.c		json_get_value_in_brackets.c \
						json_array_parse.c	json_find_in_file.c

OBJ_JSON_PARSE_NAME = $(SRC_JSON_PARSE_NAME:.c=.o)

all: $(NAME)

$(OBJ_JSON_PARSE_PATH)%.o: $(SRC_JSON_PARSE_PATH)%.c $(INC_PATH)/libft.h $(INC_PATH)/ft_json_parse.h
	@mkdir -p $(OBJ_JSON_PARSE_PATH)
	@gcc $(INC) -o $@ -c $<
	@echo -n \#

$(NAME): $(OBJ_JSON_PARSE)

re: all
