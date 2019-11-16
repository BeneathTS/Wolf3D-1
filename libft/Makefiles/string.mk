# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    string.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 13:14:32 by sleonia           #+#    #+#              #
#    Updated: 2019/11/16 04:14:16 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

NAME = libft.a
SRC_STRING_PATH = ./source/string/
OBJ_STRING_PATH = ./objects/string/
INC_PATH = ./includes/
SRC_STRING = $(addprefix $(SRC_STRING_PATH), $(SRC_STRING_NAME))
OBJ_STRING = $(addprefix $(OBJ_STRING_PATH), $(OBJ_STRING_NAME))
INC = $(addprefix -I, $(INC_PATH))

SRC_STRING_NAME = ft_atoi.c		ft_isalnum.c		ft_isprint.c		ft_strchr.c		ft_strdel.c			\
					ft_striteri.c	ft_strlen.c			ft_strncat.c		ft_strnew.c		ft_strsplit.c		\
					ft_strup.c		ft_isalpha.c		ft_strtrim.c	get_next_line.c							\
					ft_strdup.c		ft_strjoin.c		ft_strlow.c			ft_strncmp.c	ft_strnstr.c		\
					ft_strstr.c		ft_tolower.c		ft_isascii.c		ft_len_arr.c	ft_isdigit.c		\
					ft_strcmp.c		ft_strequ.c			ft_strjoin_free.c	ft_strmap.c		ft_strncpy.c		\
					ft_strrchr.c	ft_strsub.c			ft_toupper.c		ft_getnbr.c		ft_strcat.c			\
					ft_strcpy.c		ft_striter.c		ft_strlcat.c		ft_strmapi.c	ft_strnequ.c		\
					ft_strrev.c		ft_itoa.c			read_big_file.c		ft_atof.c		ft_atoi_base.c		\
					ft_isnumber.c	ft_strchrdup.c

OBJ_STRING_NAME = $(SRC_STRING_NAME:.c=.o)

all: $(NAME)

$(OBJ_STRING_PATH)%.o: $(SRC_STRING_PATH)%.c $(INC_PATH)/libft.h $(INC_PATH)/ft_string.h
	@mkdir -p $(OBJ_STRING_PATH)
	@gcc $(INC) -o $@ -c $<
	@echo -n \#

$(NAME): $(OBJ_STRING)

re: all
