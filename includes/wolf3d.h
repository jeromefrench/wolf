/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 13:23:01 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/03 10:24:36 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define FAILURE 0
# define SUCESS 1
# define TRUE 1
# define FALSE 0

# define TRIGO 10
# define ANTITRIGO 11
# define NOTHING 99

# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

# include "SDL2/SDL.h"
# include "SDL2/SDL_image.h"
# include "../libraries/libft/libft.h"
# include <errno.h>
# include <SDL_ttf.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef enum			e_window
{
	menu,
	map_editor,
	map_2d,
	map_3d
}						t_my_window;

typedef struct			s_my_point_d
{
	double				x;
	double				y;
}						t_my_point_d;

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

typedef struct			s_xyz_point
{
	double				a;
	double				b;
}						t_xyz_point;

typedef struct			s_myputtheline
{
	int					above;
	t_xyz_point			un;
	t_xyz_point			deux;
	int					ex;
	int					ey;
	int					dx;
	int					dy;
	int					d_x;
	int					d_y;
	int					i;
	int					j;
	int					x_incr;
	int					y_incr;
	float				ab;
	float				le_z1;
	float				le_z2;
}						t_myputtheline;

typedef struct			s_my_ray_casting
{
	double				distance;
	double				x;
	double				y;
	int					colision_detected;
	double				step;
	double				angle_ouverture_variable;
	double				angle_ouverture;
	double				angle_calcul;
	double				angle_calcul_rad;
	int					cmp;
	t_my_point_d		colision;
}						t_my_ray_casting;

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

typedef struct			s_my_game
{
	t_my_point			player_pos;
	t_my_rectangle		rect;
	double				ray_angle;
	double				ray_angle_rad;
	t_my_point_d		colision;
}						t_my_game;

typedef struct			s_my_menu
{
	int					arrow_h;
}						t_my_menu;

typedef struct			s_my_win
{
	t_my_menu			menu;
	t_my_game			game;
	SDL_Window			*window[2];
	SDL_Renderer		*renderer[2];
	SDL_Event			event;
	t_my_size			win_size;
	int					**map;
	int					fd;
	t_my_point			mouse_position;
	t_my_point			last_mouse_position;
	double				colision[641]; //a changer
	t_my_window			win_index;
	double				dis_project_plane;
	t_my_input			input;
}						t_my_win;

/*
**fonctions de la fenetre
*/
void					ft_create_renderer(t_my_win *s_win, int index);
void					ft_create_window(t_my_win *s_win, int index);
void					ft_clear_window(t_my_win *s_win, int index);
void					ft_get_mouse_position(t_my_win *s_win);
void					ft_put_text(t_my_win *s_win, char *str, int place, int index);
void					ft_load_bmp(t_my_win *s_win, int index);
void					ft_draw_rectangle(t_my_rectangle s_rectangle, t_my_win *s_win, int index);
void					ft_init_event(t_my_win *s_win);

/*
**gestion des erreurs
*/
void					ft_quit(t_my_win *s_win, int status);
void					ft_show_error_and_quit(t_my_win *s_win, const char *my_message);
void					ft_quit_window(t_my_win *s_win, int index);

/*
**fonctions du menu
*/
void					ft_move_the_arrow_up(t_my_win *s_win);
void					ft_move_the_arrow_down(t_my_win *s_win);
void					ft_draw_menu(t_my_win *s_win);
void					ft_display_menu(t_my_win *s_win);
void					ft_event_loop_menu(t_my_win *s_win);

/*
**fonctions de l'editeur
*/
void					ft_launch_map_editor(t_my_win *s_win);
void					ft_map_editor(t_my_win *s_win);
void					ft_put_square_on_map(t_my_win *s_win, int index);
void					ft_event_loop_editor(t_my_win *s_win);
void					ft_update_event_editor(t_my_win *s_win);
void					ft_square_follow_pointer(t_my_win *s_win);
void					ft_quit_map_editor(t_my_win *s_win);
int						**ft_init_map(t_my_win *s_win);
void					ft_save_the_map(t_my_win *s_win);

/*
**fonctions de la map
*/
void					ft_draw_map(t_my_win *s_win, int index);
void					ft_launch_map(t_my_win *s_win);
void					ft_free_the_map(t_my_win *s_win);
void					ft_read_the_map(t_my_win *s_win);
int						ft_my_atoi(char c);

/*
**fonctions map gameplay
*/
void					ft_event_loop_map(t_my_win *s_win);
void					ft_move_square(int move, t_my_win *s_win);
void					ft_init_square_pos(t_my_win *s_win);

/*
**bresename
*/
void					ft_draw_line(t_my_win *s_win, t_myputtheline *s_line);
void					ft_case_one(t_my_win *s_win, t_myputtheline *s_line);
void					ft_case_two(t_my_win *s_win, t_myputtheline *s_line);
void					ft_case_three(t_my_win *s_win, t_myputtheline *s_line);
void					ft_case_four(t_my_win *s_win, t_myputtheline *s_line);
void					ft_case_five(t_my_win *s_win, t_myputtheline *s_line);

t_xyz_point				ft_turn_vector(t_xyz_point vector, double angle);
void					ft_draw_player(t_my_win *s_win);
void					ft_ray_casting(t_my_win *s_win, int angle);
void					ft_draw_map_3d(t_my_win *s_win);

/*
**ray casting
*/
int						ft_test_colision(t_my_win *s_win);
int						ft_init_angle(int move);

void					ft_pointer_moving_player(t_my_win *s_win);
#endif
