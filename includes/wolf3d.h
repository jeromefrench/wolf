#ifndef WOLF3D_H
# define WOLF3D_H

# define FAILURE 0
# define SUCESS 1

# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include <stdio.h>
# include "../libraries/libft/libft.h"
# include <errno.h>


typedef struct			s_my_point
{
	int					x;
	int					y;
}						t_my_point;

typedef struct			s_my_size
{
	int					width;
	int					height;
}						t_my_size;

typedef struct			s_my_rectangle
{
	t_my_point			point;
	t_my_size			size;
}						t_my_rectangle;


typedef struct			s_my_win
{
	int					i;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			event;
	t_my_size			win_size;
}						t_my_win;

typedef struct			s_my_input
{
	SDL_bool			key[SDL_NUM_SCANCODES];
	SDL_bool			quit;
	int					x;
	int					y;
	int					xrel;
	int					yrel;
	int					xwheel;
	int					ywheel;
	SDL_bool			mouse[6];
}						t_my_input;


void					ft_quit(t_my_win *s_win, int status);
void					ft_show_error_and_quit(t_my_win *s_win, const char *my_message);
void					ft_get_mouse_position(void);

#endif
