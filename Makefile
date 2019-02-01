# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by jchardin          #+#    #+#              #
#    Updated: 2019/02/01 14:15:28 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = main.c


OBJ = $(SRC:.c=.o)
SRC_Dir = ./srcs/
OBJ_Dir = ./objs/
CSources = $(addprefix $(SRC_Dir), $(SRC))
CObjects = $(addprefix $(OBJ_Dir), $(OBJ))
FLAGS = -Wall -Wextra -Werror
CC = gcc -g -v
LIBRARIES = -L ./libraries/libui -lSDL2 -L ./libraries/libui -lSDL2_image -framework OpenGL ./libraries/libft/libft.a
INCLUDES  = -I ./includes

$(NAME):$(CObjects)
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


defaut:
	gcc -g main.c -o $(NAME) -I /Users/jchardin/.brew/Cellar/sdl2/2.0.9/include/ -L ./libui -lSDL2 -L ./libui -lSDL2_image -framework GLUT -framework OpenGL ./libft/libft.a
	ctags -R .
