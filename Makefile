.PHONY: all, $(NAME), norm, clean, fclean, re

#****************************************************************************#
#					SETTINGS FOR CONCLUSION IN CONSOLE 						 #
#****************************************************************************#

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
#									TESTS 									 #
#****************************************************************************#

NAME = wolf3D

FRAMEDIR = /Users/$(USER)/Library/Frameworks

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
INC_PATH = ./includes/
LIB_PATH = ./libft/
MLX_PATH = ./mlx/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))
INC_SDL = 		-I Frameworks/SDL2.framework/Versions/A/Headers 		\
				-I Frameworks/SDL2_image.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_ttf.framework/Versions/A/Headers 	\
				-I Frameworks/SDL2_mixer.framework/Versions/A/Headers/ 	\
				-F Frameworks/

FRAME = 	-F Frameworks/ -framework SDL2 -framework SDL2_image 		\
            -framework SDL2_ttf -framework SDL2_mixer -rpath Frameworks/

FLAGS = 	-Wall -Werror -Wextra -Ofast -g

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -framework OpenCL

SRC_NAME =	main.c 						\
			init_game_data.c 			\
			init_env.c 					\
			reader.c 					\
			renderer.c 					\
			ray_caster.c 				\
			hooks.c 					\
			load_textures.c 			\
			mouse_controls.c 			\
			menu_data_load.c 			\
			menu.c 						\
			close.c						\
			get_texture_name.c			\
			menu_controls.c				\
			settings.c					\
			settings_data_load.c		\
			settings_controls.c			\
			music_manager.c				\
			move.c						\
			chooser_data_load.c			\
			chooser.c					\
			chooser_controls.c			\
			menu_add_bttns_control.c	\
			load_additional_buttons.c	\
			audio.c						\
			player_weapon.c				\
			chooser_scroller.c			\

SRC_SDL_AUDIO = ./Simple-SDL2-Audio/src/audio.c

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make lib_refresh
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -lm -L $(LIB_PATH) $(INC_SDL) $(FRAME) -lft -L $(MLX_PATH) $(MLX_FLAGS)
	 
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)/wolf3d.h $(INC_PATH)/define_value.h
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)Simple-SDL2-Audio/src/
	@gcc -g $(INC) $(INC_SDL) -o $@ -c $<

#****************************************************************************#
#									OTHER			 						 #
#****************************************************************************#

$(FRAMEDIR):
		@mkdir -p $(FRAMEDIR)
		@rm -rf $(FRAMEDIR)/*

#	Need to copy SDL to your Frameworks
# $(FRAME): $(FRAMEDIR)/%: Frameworks/%
# 		@cp -R $< $(FRAMEDIR)

lib_refresh:
	@make -C $(LIB_PATH)
	@make -C $(MLX_PATH)
	@echo ""
	@echo "\n\t\t        $(BLUE)💥 WOLF3D READY!💥\t\t     "
	@echo "💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀\
💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀"

norm:
	@echo "$(YELLOW)"
	@norminette -R CheckForbiddenSourceHeader

clean:
	@find . -name ".DS_Store" -delete
	@clear
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)
	@make clean -C $(MLX_PATH)

re: fclean all