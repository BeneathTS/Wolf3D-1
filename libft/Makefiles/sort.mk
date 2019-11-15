# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sort.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 13:13:27 by sleonia           #+#    #+#              #
#    Updated: 2019/11/12 13:46:31 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a
SRC_SORT_PATH = ./source/sort/
OBJ_SORT_PATH = ./objects/sort/
INC_PATH = ./includes/
SRC_SORT = $(addprefix $(SRC_SORT_PATH), $(SRC_SORT_NAME))
OBJ_SORT = $(addprefix $(OBJ_SORT_PATH), $(OBJ_SORT_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_SORT_NAME = my_bubble_sort.c  my_quick_sort.c

OBJ_SORT_NAME = $(SRC_SORT_NAME:.c=.o)

all: $(NAME)

$(OBJ_SORT_PATH)%.o: $(SRC_SORT_PATH)%.c $(INC_PATH)/libft.h $(INC_PATH)/ft_sort.h
	@mkdir -p $(OBJ_SORT_PATH)
	@gcc $(INC) -o $@ -c $<
	@echo -n \#

$(NAME): $(OBJ_SORT)

re: all
