NAME = Wolf3D

SOURCES = main.c \

SRCDIR = sources

OBJECTS = $(SOURCES:.c=.o)

INCLUDES = -I includes

LIB = -I libft/includes

vpath %.c $(SRCDIR)

CFLAGS = -Wall -Wextra -Werror

.PHONY: all lib clean fclean re clterm

all: lib $(NAME)

$(NAME): $(OBJECTS)
	@gcc $(CFLAGS) $^ $(INCLUDES) $(LIB) -o $(NAME) 

$(OBJECTS): $(SOURCES)
	@gcc $(CFLAGS) -c $^ $(INCLUDES) $(LIB)

lib:
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: clean fclean all

clterm:
	clear && printf '\033[3J'