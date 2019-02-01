#ifndef WOLF3D_H
# define WOLF3D_H

# define FAILURE 0
# define SUCESS 1

# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include <stdio.h>
# include "../libraries/libft/libft.h"
# include <errno.h>

typedef struct			s_my_win
{
	int					i;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
}						t_my_win;


void					ft_quit(t_my_win *s_win, int status);
void					ft_show_error_and_quit(t_my_win *s_win, const char *my_message);

#endif
