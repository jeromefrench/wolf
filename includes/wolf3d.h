#ifndef WOLF3D_H
# define WOLF3D_H

# define FAILURE 0
# define SUCESS 1
# define TRUE 1
# define FALSE 0

# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include <stdio.h>
# include "../libraries/libft/libft.h"
# include <errno.h>
# include <SDL_ttf.h>
# include <fcntl.h>

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
	int					mouse_move;
	int					mouse_clic;
}						t_my_input;

typedef struct			s_my_put_smth
{
	int					text_w;
	int					text_h;
	SDL_Color			color;
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	SDL_Rect			dstrect;
	TTF_Font			*font;
}						t_my_put_smth;


typedef struct			s_my_menu
{
	t_my_input			input;
	int					arrow_h;
}						t_my_menu;

typedef struct			s_my_editor
{
	t_my_input			input;
}						t_my_editor;

typedef struct			s_my_win
{
	t_my_menu			menu;
	t_my_editor			editor;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Event			event;
	t_my_size			win_size;
	int					**map;
    int                 fd;
	t_my_point			mouse_position;
}						t_my_win;


//fonctions de la fenetre
void					ft_create_renderer(t_my_win *s_win);
void					ft_create_window(t_my_win *s_win);
void					ft_clear_window(t_my_win *s_win);
void					ft_get_mouse_position(t_my_win *s_win);
void					ft_put_text(t_my_win *s_win, char *str, int place);
void					ft_load_bmp(t_my_win *s_win); 
void					ft_draw_rectangle(t_my_rectangle s_rectangle, t_my_win *s_win);

//gestion des erreurs
void					ft_quit(t_my_win *s_win, int status);
void					ft_show_error_and_quit(t_my_win *s_win, const char *my_message);

//fonctions du menu
void					ft_move_the_arrow_up(t_my_win *s_win);
void					ft_move_the_arrow_down(t_my_win *s_win);
void					ft_draw_menu(t_my_win *s_win);
void					ft_display_menu(t_my_win *s_win);
void					ft_event_loop_menu(t_my_win *s_win);

//fonctions de l'editeur
void					ft_launch_map_editor(t_my_win *s_win);
void					ft_map_editor(t_my_win *s_win);
void					ft_put_square_on_map(t_my_win *s_win);
void					ft_event_loop_editor(t_my_win *s_win);
void					ft_update_event_editor(t_my_win *s_win);
void					ft_square_follow_pointer(t_my_win *s_win);
void					ft_quit_map_editor(t_my_win *s_win);
int						**ft_init_map(t_my_win *s_win);
void		            ft_save_the_map(t_my_win *s_win);

//fonctions de la map
void					ft_draw_map(t_my_win *s_win);
void					ft_launch_map(t_my_win *s_win);

#endif
