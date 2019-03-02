# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by jchardin          #+#    #+#              #
#    Updated: 2019/03/02 10:24:42 by jchardin         ###   ########.fr        #
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
file_map_3d.c \
file_ft_ray_casting.c

OBJ = $(SRC:.c=.o)
SRC_Dir = ./srcs/
OBJ_Dir = ./objs/
CSources = $(addprefix $(SRC_Dir), $(SRC))
CObjects = $(addprefix $(OBJ_Dir), $(OBJ))
FLAGS = -Wall -Wextra -Werror
CC = gcc

LIBRARIES = -L ./libraries/sdl2/sdl2/lib -lSDL2 \
			-L ./libraries/sdl2_image/sdl2_image/lib -lSDL2_image -framework OpenGL \
			-L ./libraries/libft -lft  \
			-L ./libraries/sdl2_ttf/sdl2_ttf/lib -lSDL2_ttf


INCLUDES  = -I ./includes


$(NAME):clear $(CObjects)
	#@make -C ./libraries/libft
	$(CC) $(DEBUG) $(FLAGS) $(INCLUDES) $(LIBRARIES) $(CObjects) -o $(NAME)
	ctags -R ./srcs/

$(OBJ_Dir)%.o:$(SRC_Dir)%.c
	@mkdir $(OBJ_Dir) 2> /dev/null || true
	$(CC) $(DEBUG) $(FLAGS) $(INCLUDES) -c $< -o $@


lib: libft sdl2 sdl2_image freetype sdl2_ttf


debug: DEBUG = -g
debug: $(NAME)


libft:
	@mkdir ./libraries 2> /dev/null || true
	cp -r ./source_lib/libft ./libraries/
	make -C ./libraries/libft

sdl2:
	@mkdir ./libraries 2> /dev/null || true
	mkdir ./libraries/sdl2 2> /dev/null || true
	tar xzf ./source_lib/SDL2-2.0.9.tar.gz -C ./libraries/sdl2/
	mv ./libraries/sdl2/SDL2-2.0.9 ./libraries/sdl2/sdl2
	cd  ./libraries/sdl2/sdl2 ; ./configure --prefix=$(shell pwd)/libraries/sdl2/sdl2
	make -C ./libraries/sdl2/sdl2
	make -C ./libraries/sdl2/sdl2 install


sdl2_image:
	@mkdir ./libraries 2> /dev/null || true
	mkdir ./libraries/sdl2_image 2> /dev/null || true
	tar xzf ./source_lib/SDL2_image-2.0.4.tar.gz -C ./libraries/sdl2_image/
	mv ./libraries/sdl2_image/SDL2_image-2.0.4 ./libraries/sdl2_image/sdl2_image
	cd ./libraries/sdl2_image/sdl2_image/ ; ./configure --prefix=$(shell pwd)/libraries/sdl2_image/sdl2_image --with-sdl-prefix=$(shell pwd)/libraries/sdl2/sdl2
	make -C ./libraries/sdl2_image/sdl2_image
	make -C ./libraries/sdl2_image/sdl2_image install

freetype:
	@mkdir ./libraries 2> /dev/null || true
	mkdir ./libraries/freetype 2> /dev/null || true
	tar xzf ./source_lib/freetype-2.4.11.tar.gz -C ./libraries/freetype/
	mv ./libraries/freetype/freetype-2.4.11 ./libraries/freetype/freetype
	cd ./libraries/freetype/freetype ; ./configure --prefix=$(shell pwd)/libraries/freetype/freetype
	make -C ./libraries/freetype/freetype/
	make -C ./libraries/freetype/freetype/ install

sdl2_ttf:
	@mkdir ./libraries 2> /dev/null || true
	mkdir ./libraries/sdl2_ttf 2> /dev/null || true
	tar xzf ./source_lib/SDL2_ttf-2.0.15.tar.gz -C ./libraries/sdl2_ttf
	mv ./libraries/sdl2_ttf/SDL2_ttf-2.0.15/ ./libraries/sdl2_ttf/sdl2_ttf
	cd ./libraries/sdl2_ttf/sdl2_ttf ;  ./configure --prefix=$(shell pwd)/libraries/sdl2_ttf/sdl2_ttf --with-sdl-prefix=$(shell pwd)/libraries/sdl2/sdl2
	make -C libraries/sdl2_ttf/sdl2_ttf/
	make -C libraries/sdl2_ttf/sdl2_ttf/ install

clean:
	#make fclean -C ./libraries/libft
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


.PHONY: tag

