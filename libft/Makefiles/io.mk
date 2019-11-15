# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    io.mk                                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 12:58:25 by sleonia           #+#    #+#              #
#    Updated: 2019/11/12 13:45:50 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a
SRC_IO_PATH = ./source/io/
OBJ_IO_PATH = ./objects/io/
INC_PATH = ./includes/
SRC_IO = $(addprefix $(SRC_IO_PATH), $(SRC_IO_NAME))
OBJ_IO = $(addprefix $(OBJ_IO_PATH), $(OBJ_IO_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_IO_NAME = 		ft_putchar.c		ft_putendl_fd.c		ft_putnbr_fd.c		ft_putstr_fd.c					\
					ft_putchar_fd.c		ft_putendl.c		ft_putnbr.c			ft_putnbr_fd.c		ft_putstr.c	\
					print_arr_str.c		putstr_color.c		putchar_color.c

OBJ_IO_NAME = $(SRC_IO_NAME:.c=.o)

all: $(NAME)

$(OBJ_IO_PATH)%.o: $(SRC_IO_PATH)%.c $(INC_PATH)/libft.h $(INC_PATH)/ft_io.h
	@mkdir -p $(OBJ_IO_PATH)
	@gcc $(INC) -o $@ -c $<
	@echo -n \#

$(NAME): $(OBJ_IO)

re: all
