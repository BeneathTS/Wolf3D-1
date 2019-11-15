# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 13:09:26 by sleonia           #+#    #+#              #
#    Updated: 2019/11/12 13:39:56 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a
SRC_ERROR_PATH = ./source/error/
OBJ_ERROR_PATH = ./objects/error/
INC_PATH = ./includes/
SRC_ERROR = $(addprefix $(SRC_ERROR_PATH), $(SRC_ERROR_NAME))
OBJ_ERROR = $(addprefix $(OBJ_ERROR_PATH), $(OBJ_ERROR_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_ERROR_NAME = 	malloc_error.c		int_error.c			char_error.c		void_error.c		ft_exit.c

OBJ_ERROR_NAME = $(SRC_ERROR_NAME:.c=.o)

all: $(NAME)

$(OBJ_ERROR_PATH)%.o: $(SRC_ERROR_PATH)%.c $(INC_PATH)/libft.h $(INC_PATH)/ft_error.h
	@mkdir -p $(OBJ_ERROR_PATH)
	@gcc $(INC) -o $@ -c $<
	@echo -n \#

$(NAME): $(OBJ_ERROR)

re: all
