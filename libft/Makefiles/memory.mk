# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    memory.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 13:12:02 by sleonia           #+#    #+#              #
#    Updated: 2019/11/12 13:46:24 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a
SRC_MEMORY_PATH = ./source/memory/
OBJ_MEMORY_PATH = ./objects/memory/
INC_PATH = ./includes/
SRC_MEMORY = $(addprefix $(SRC_MEMORY_PATH), $(SRC_MEMORY_NAME))
OBJ_MEMORY = $(addprefix $(OBJ_MEMORY_PATH), $(OBJ_MEMORY_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_MEMORY_NAME = 	ft_destroy_int_arr.c	ft_destroy_string_arr.c	ft_memalloc.c	ft_memccpy.c	ft_memchr.c	\
					ft_memcmp.c				ft_memcpy.c				ft_memdel.c		ft_memmove.c	ft_memset.c	\
					ft_bzero.c				ft_memdel_with_1_ptr.c

OBJ_MEMORY_NAME = $(SRC_MEMORY_NAME:.c=.o)

all: $(NAME)

$(OBJ_MEMORY_PATH)%.o: $(SRC_MEMORY_PATH)%.c $(INC_PATH)/libft.h $(INC_PATH)/ft_memory.h
	@mkdir -p $(OBJ_MEMORY_PATH)
	@gcc $(INC) -o $@ -c $<
	@echo -n \#

$(NAME): $(OBJ_MEMORY)

re: all
