# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by jchardin          #+#    #+#              #
#    Updated: 2019/02/04 17:48:07 by jchardin         ###   ########.fr        #
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
file_mouse_position.c



OBJ = $(SRC:.c=.o)
SRC_Dir = ./srcs/
OBJ_Dir = ./objs/
CSources = $(addprefix $(SRC_Dir), $(SRC))
CObjects = $(addprefix $(OBJ_Dir), $(OBJ))
FLAGS = -Wall -Wextra -Werror
CC = gcc -g
LIBRARIES = -L ./libraries/libui -lSDL2 -L ./libraries/libui -lSDL2_image -framework OpenGL -L ./libraries/libft  -lft  -L /Users/jchardin/.brew/Cellar/sdl2_ttf/2.0.14/lib -lSDL2_ttf
INCLUDES  = -I ./includes

$(NAME):clear $(CObjects)
	make -C ./libraries/libft
	$(CC) $(FLAGS) $(INCLUDES) $(LIBRARIES) $(CObjects) -o $(NAME)
	ctags -R .

$(OBJ_Dir)%.o:$(SRC_Dir)%.c
	mkdir $(OBJ_Dir) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


clean:
	make fclean -C ./libraries/libft
	/bin/rm -rf $(OBJ_Dir)

fclean:clean
	/bin/rm -rf $(NAME)

re:fclean $(NAME)

me:
	norminette $(SRC_Dir) $(OBJ_Dir)

exe:
	./$(NAME)

clear:
	clear

