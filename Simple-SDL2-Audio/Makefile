# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 13:03:20 by sleonia           #+#    #+#              #
#    Updated: 2019/12/03 15:00:11 by sleonia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

NAME = libsdl_audio.a

INC = audio.h
SRC = audio.c
OBJ = $(SRC:.c=.o)

INC_SDL = 		-I ../Frameworks/SDL2.framework/Versions/A/Headers 		\
				-I ../Frameworks/SDL2_image.framework/Versions/A/Headers 	\
				-I ../Frameworks/SDL2_ttf.framework/Versions/A/Headers 	\
				-I ../Frameworks/SDL2_mixer.framework/Versions/A/Headers/ 	\
				-F ../Frameworks/

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c $(INC)
	@gcc -Wall -Werror -Wextra -c $(INC_SDL) $<

clean: 
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
