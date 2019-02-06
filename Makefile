# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpelissi <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by lpelissi          #+#    #+#              #
#    Updated: 2019/02/05 14:53:18 by lpelissi         ###   ########.fr        #
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
	  file_ft_editor.c

OBJ = $(SRC:.c=.o)
	SRC_Dir = ./srcs/
	OBJ_Dir = ./objs/
	CSources = $(addprefix $(SRC_Dir), $(SRC))
	CObjects = $(addprefix $(OBJ_Dir), $(OBJ))
	FLAGS = -Wall -Wextra -Werror
	CC = gcc -g  
	LIBRARIES =   -framework OpenGL -L ./libraries/libft  -lft  -L ./libraries/SDL2_ttf/2.0.14/lib -lSDL2_ttf
	INCLUDES  = -I ./includes -I ./libraries/sdl2_ttf/2.0.14/include/SDL2 -I ./libraries/sdl2/include/SDL2
$(NAME):clear $(CObjects)
	make -C ./libraries/libft 
	$(CC) $(FLAGS) $(INCLUDES) $(LIBRARIES) $(CObjects) $(sdl2-config --cflags) -o $(NAME) 
	#ctags -R .

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

