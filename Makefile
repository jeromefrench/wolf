# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 11:46:21 by jchardin          #+#    #+#              #
#    Updated: 2019/01/29 14:27:22 by jchardin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

all:
	gcc -g main.c -o $(NAME) -I /Users/jchardin/.brew/Cellar/sdl2/2.0.9/include/ -L ./libui -lSDL2 -L ./libui -lSDL2_image
