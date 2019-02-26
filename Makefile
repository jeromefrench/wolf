# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by jchardin          #+#    #+#              #
#    Updated: 2019/02/26 14:45:40 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c \
file_quit.c \
file_window.c \
file_renderer.c \
file_menu.c \
file_map_editor.c \
file_draw_rectangle.c \
file_mouse_position.c \
file_ft_menu.c \
file_ft_editor.c \
file_load_the_map.c \
file_move_square.c \
file_bresename.c \
file_line_case.c \
file_ft_editor_seconde.c \
file_ray_casting.c \
file_read_map.c \
file_map_2d.c \
file_ft_ray_casting.c

OBJ = $(SRC:.c=.o)
SRC_Dir = ./srcs/
OBJ_Dir = ./objs/
CSources = $(addprefix $(SRC_Dir), $(SRC))
CObjects = $(addprefix $(OBJ_Dir), $(OBJ))
FLAGS = -Wall -Wextra -Werror
CC = gcc -g
LIBRARIES = -L ./libraries/sdl/SDL2-2.0.9/lib -lSDL2 \
			-L ./libraries/sdl_image/SDL2_image-2.0.4/lib -lSDL2_image -framework OpenGL \
			-L ./libraries/libft -lft  \
			-L ./libraries/sdl_ttf/SDL2_ttf-2.0.15/lib -lSDL2_ttf


INCLUDES  = -I ./includes

$(NAME):clear $(CObjects)
	@make -C ./libraries/libft
	$(CC) $(FLAGS) $(INCLUDES) $(LIBRARIES) $(CObjects) -o $(NAME)
	ctags -R .

$(OBJ_Dir)%.o:$(SRC_Dir)%.c
	@mkdir $(OBJ_Dir) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

sdl:
	./configure --prefix==pwd
	make
	make install
	mkdir lib

sdl_image:
	./configure CPPFLAGS="-I/Users/jchardin/wolf/libraries/sdl/SDL2-2.0.9/include" LDFLAGS="-L/Users/jchardin/wolf/libraries/sdl/SDL2-2.0.9/lib" --prefix=/Users/jchardin/wolf/libraries/sdl_image/SDL2_image-2.0.4
	make
	make install

freetype:
	./configure --prefix=/Users/jchardin/wolf/libraries/freetype/freetype2
	make
	make install

sdl_ttf:
	./configure --prefix=./configure --prefix=/Users/jchardin/wolf/libraries/sdl_ttf/SDL2_ttf-2.0.15 --with-sdl-prefix=/Users/jchardin/wolf/libraries/sdl/SDL2-2.0.9
	make
	make install

clean:
	make fclean -C ./libraries/libft
	/bin/rm -rf $(OBJ_Dir)

fclean:clean
	/bin/rm -rf $(NAME)

re:fclean $(NAME)

norme:clear
	@echo "La norme\n";
	norminette $(SRC_Dir)

exe:
	./$(NAME)

clear:
	clear

line:clear
	find ./srcs -name '*.c' | xargs wc -l

tag:
	ctags -R .
