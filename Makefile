NAME = wolf3d

SRC =	main.c \
		init_game_data.c \
		init_env.c \
		reader.c \
		renderer.c \
		ray_caster.c \
		hooks.c \
		load_textures.c \
		mouse_controls.c \
		menu_data_load.c \
		menu.c \
		level_chooser.c \
		close.c

OS = $(SRC:.c=.o)

vpath %.c sources

CFLAGS = -Wall -Wextra -Werror

L_MLX = -L /usr/local/lib

I_MLX = -I /usr/local/include

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -framework OpenCL

HDRS = -I includes

LIBHDR = -I libft/includes

LIB = libft/libft.a

.PHONY: all lib clean fclean re clterm

all: lib $(NAME)

$(NAME): $(OS)
	gcc $(CFLAGS) $(MLXFLAGS) $^ $(LIB) $(L_MLX) $(I_MLX) -o $(NAME)

$(OS): $(SRC)
	gcc $(CFLAGS) $^ $(LIBHDR) $(HDRS) $(I_MLX) -c

lib:
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OS)

fclean: 
	@make -C libft fclean
	@rm -f $(OS)
	@rm -f $(NAME)

re: fclean all

clterm:
	clear && printf '\033[3J'