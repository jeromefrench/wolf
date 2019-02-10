# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by jchardin          #+#    #+#              #
#    Updated: 2019/02/10 18:48:41 by jchardin         ###   ########.fr        #
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
LIBRARIES = -L ./libraries/libui -lSDL2 -L ./libraries/libui -lSDL2_image -framework OpenGL -L ./libraries/libft  -lft  -L /Users/jchardin/.brew/Cellar/sdl2_ttf/2.0.14/lib -lSDL2_ttf
INCLUDES  = -I ./includes

$(NAME):clear $(CObjects)
	@make -C ./libraries/libft
	$(CC) $(FLAGS) $(INCLUDES) $(LIBRARIES) $(CObjects) -o $(NAME)
	ctags -R .

$(OBJ_Dir)%.o:$(SRC_Dir)%.c
	@mkdir $(OBJ_Dir) 2> /dev/null || true
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

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
