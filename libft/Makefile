# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 18:14:41 by sleonia           #+#    #+#              #
#    Updated: 2019/11/12 18:21:16 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), norm, clean, fclean, re

#****************************************************************************#
#					SETTINGS FOR CONCLUSION IN CONSOLE 						 #
#****************************************************************************#

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
NORMAL = \033[0m

#****************************************************************************#
#									LIBFT 									 #
#****************************************************************************#

NAME = libft.a

MAKE_DIR = ./Makefiles/
OBJ_PATH = ./objects/
OBJ_ERROR_PATH = ./objects/error/*
OBJ_IO_PATH = ./objects/io/*
OBJ__JSON_PARSE_PATH = ./objects/json_parse/*
OBJ_MEMORY_PATH = ./objects/memory/*
OBJ_SORT_PATH = ./objects/sort/*
OBJ_STRING_PATH = ./objects/string/*
OBJ_VECTOR_PATH = ./objects/vector/*

OBJ = $(OBJ_ERROR_PATH) $(OBJ_IO_PATH) $(OBJ_JSON_PARSE_PATH) $(OBJ_MEMORY_PATH) $(OBJ_SORT_PATH) $(OBJ_STRING_PATH) $(OBJ_VECTOR_PATH)

#****************************************************************************#
#									ALL 									 #
#****************************************************************************#

all: $(NAME)

$(NAME):
	@make -f $(MAKE_DIR)error.mk
	@make -f $(MAKE_DIR)io.mk
	@make -f $(MAKE_DIR)json_parse.mk
	@make -f $(MAKE_DIR)memory.mk
	@make -f $(MAKE_DIR)sort.mk
	@make -f $(MAKE_DIR)string.mk
	@make -f $(MAKE_DIR)vector.mk
	@echo "\n\t\t\t$(PINK)🎊 LIBFT READY!🎊$(BLACK)"
	@ar -rc $(NAME) $(OBJ) $?
	@ranlib $(NAME)

#****************************************************************************#
#									OTHER			 						 #
#****************************************************************************#

norm:
	norminette -R CheckForbiddenSourceHeader

clean: 
	@/bin/rm -rf $(OBJ_PATH)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
