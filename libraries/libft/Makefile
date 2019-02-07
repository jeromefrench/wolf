# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 11:00:56 by lpelissi          #+#    #+#              #
#    Updated: 2019/01/09 11:33:34 by lpelissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -I ./includes -Wall -Wextra -Werror

OPTIONS = -c

SOURCE = ft_atoi.c \
		 ft_bzero.c \
		 ft_isalnum.c \
		 ft_isalpha.c \
		 ft_isascii.c \
		 ft_isdigit.c \
		 ft_isprint.c \
		 ft_memccpy.c \
		 ft_memchr.c \
		 ft_memcmp.c \
		 ft_memcpy.c \
		 ft_memmove.c \
		 ft_memset.c \
		 ft_strcat.c \
		 ft_strchr.c \
		 ft_strcmp.c \
		 ft_strcpy.c \
		 ft_strdup.c \
		 ft_strlcat.c \
		 ft_strlen.c \
		 ft_strncat.c \
		 ft_strncmp.c \
		 ft_strncpy.c \
		 ft_strnstr.c \
		 ft_strrchr.c \
		 ft_strstr.c \
		 ft_tolower.c \
		 ft_toupper.c \
		 ft_itoa.c \
		 ft_putendl.c \
		 ft_putstr_fd.c \
		 ft_striteri.c \
		 ft_strnew.c \
		 ft_memalloc.c \
		 ft_putendl_fd.c \
		 ft_strclr.c \
		 ft_strjoin.c \
		 ft_strsplit.c \
		 ft_memdel.c \
		 ft_putnbr.c \
		 ft_strdel.c \
		 ft_strmap.c \
		 ft_strsub.c \
		 ft_putchar.c \
		 ft_putnbr_fd.c \
		 ft_strequ.c \
		 ft_strmapi.c \
		 ft_strtrim.c \
		 ft_putchar_fd.c \
		 ft_putstr.c \
		 ft_striter.c \
		 ft_strnequ.c \
		 ft_lstnew.c \
		 ft_lstdelone.c \
		 ft_lstdel.c \
		 ft_lstadd.c \
		 ft_lstiter.c \
		 ft_lstmap.c \
		 ft_print_words_tables.c \
		 ft_strtrimc.c \
		 ft_pow.c \
		 ft_sqrt.c \
		 ft_str_is_numeric.c \
		 get_next_line.c

OBJECTS = ft_atoi.o \
		  ft_bzero.o \
		  ft_isalnum.o \
		  ft_isalpha.o \
		  ft_isascii.o \
		  ft_isdigit.o \
		  ft_isprint.o \
		  ft_memccpy.o \
		  ft_memchr.o \
		  ft_memcmp.o \
		  ft_memcpy.o \
		  ft_memmove.o \
		  ft_memset.o \
		  ft_strcat.o \
		  ft_strchr.o \
		  ft_strcmp.o \
		  ft_strcpy.o \
		  ft_strdup.o \
		  ft_strlcat.o \
		  ft_strlen.o \
		  ft_strncat.o \
		  ft_strncmp.o \
		  ft_strncpy.o \
		  ft_strnstr.o \
		  ft_strrchr.o \
		  ft_strstr.o \
		  ft_tolower.o \
		  ft_toupper.o \
		  ft_itoa.o \
          ft_putendl.o \
          ft_putstr_fd.o \
          ft_striteri.o \
          ft_strnew.o \
          ft_memalloc.o \
          ft_putendl_fd.o \
          ft_strclr.o \
          ft_strjoin.o \
          ft_strsplit.o \
          ft_memdel.o \
          ft_putnbr.o \
          ft_strdel.o \
          ft_strmap.o \
          ft_strsub.o \
          ft_putchar.o \
          ft_putnbr_fd.o \
          ft_strequ.o \
          ft_strmapi.o \
          ft_strtrim.o \
          ft_putchar_fd.o \
          ft_putstr.o \
          ft_striter.o \
          ft_strnequ.o \
		  ft_lstnew.o \
		  ft_lstdelone.o \
		  ft_lstdel.o \
		  ft_lstadd.o \
		  ft_lstiter.o \
		  ft_lstmap.o \
		  ft_print_words_tables.o \
		  ft_strtrimc.o \
		  ft_pow.o \
		  ft_sqrt.o \
		  ft_str_is_numeric.o \
		  get_next_line.o
 
all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(OPTIONS) $(CFLAGS) $(SOURCE)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -rf $(OBJECTS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
