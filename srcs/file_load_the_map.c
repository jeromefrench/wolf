/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load_the_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:37:57 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/07 16:44:35 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_launch_map(t_my_win *s_win)
{
	ft_create_window(s_win);
	ft_create_renderer(s_win);
	ft_clear_window(s_win);
	s_win->map = ft_init_map(s_win);
	ft_read_the_map(s_win);
	ft_draw_map(s_win);
	ft_init_square_pos(s_win);
	s_win->game.ray_angle = 0;
	SDL_RenderPresent(s_win->renderer);
	ft_event_loop_map(s_win);
}

void			ft_ray_tracing(t_my_win *s_win, int angle)
{
	t_myputtheline	s_line;
	double			angle_r;

	double			angle_ouverture;
	double			angle_calcul_r;
	double			distance;
	angle_ouverture = 50;

	if(angle == TRIGO)
		s_win->game.ray_angle += 5;
	else if (angle == ANTITRIGO)
		s_win->game.ray_angle -= 5;

	s_line.un.a = s_win->game.square_pos.x;
	s_line.un.b = s_win->game.square_pos.y;


	distance = 100;
	double	x = 0;
	double	y = distance;

	//rayon droit
	angle_r = s_win->game.ray_angle * 3.14 / 180;
	//rotation
	s_line.deux.a = (x * cos(angle_r)) + (y * -sin(angle_r));
	s_line.deux.b = (x * sin(angle_r)) + (y *  cos(angle_r));
	//translation
	s_line.deux.a += s_win->game.square_pos.x;
	s_line.deux.b += s_win->game.square_pos.y;
	ft_put_the_line_third(s_win, &s_line);


	//demi cercle
	double angle_calcul;
	angle_calcul = (180 - angle_ouverture) / 2;
	int i = 0;
	while(i < (angle_ouverture * 2))
	{
		angle_calcul = (180 - angle_ouverture + i) / 2;
		angle_calcul_r = angle_calcul * 3.14 / 180;
		x = cos(angle_calcul_r) * distance;
		y = sin(angle_calcul_r) * distance;
		//rotation
		s_line.deux.a = (x * cos(angle_r)) + (y * -sin(angle_r));
		s_line.deux.b = (x * sin(angle_r)) + (y *  cos(angle_r));
		//translation
		s_line.deux.a += s_win->game.square_pos.x;
		s_line.deux.b += s_win->game.square_pos.y;
		ft_put_the_line_third(s_win, &s_line);
		i++;
	}
}




t_xyz_point		ft_turn_vector(t_xyz_point vector, double angle)
{
	angle = angle * 3.14 / 180;
	vector.a = (vector.a * cos(angle)) + (vector.b * sin(angle));
	vector.b = (vector.a * -sin(angle)) + (vector.b * cos(angle));
	return (vector);
}



void			ft_init_event_map(t_my_win *s_win)
{
	s_win->game.input.key[SDL_SCANCODE_ESCAPE] = FALSE;
	s_win->game.input.quit = FALSE;
	s_win->game.input.key[SDL_SCANCODE_W] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_S] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_A] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_D] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_LEFT] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_RIGHT] = FALSE;
}

void			ft_update_event_map(t_my_win *s_win)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			s_win->game.input.quit = SDL_TRUE;
		else if (event.type == SDL_KEYDOWN)
			s_win->game.input.key[event.key.keysym.scancode] = SDL_TRUE;
		else if (event.type == SDL_MOUSEMOTION)
			s_win->game.input.mouse_move = 1;
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			s_win->game.input.mouse_clic = 1;
		SDL_Delay(2);
	}
}

void			ft_event_loop_map(t_my_win *s_win)
{

	ft_init_event_map(s_win);
	while (!s_win->game.input.quit)
	{
		ft_update_event_map(s_win);
		if (s_win->game.input.key[SDL_SCANCODE_ESCAPE])
			ft_display_menu(s_win);
		else if(s_win->game.input.key[SDL_SCANCODE_W])
			ft_move_square(UP, s_win);
		else if(s_win->game.input.key[SDL_SCANCODE_S])
			ft_move_square(DOWN, s_win);
		else if(s_win->game.input.key[SDL_SCANCODE_A])
			ft_move_square(LEFT, s_win);
		else if(s_win->game.input.key[SDL_SCANCODE_D])
			ft_move_square(RIGHT, s_win);
		else if(s_win->game.input.key[SDL_SCANCODE_LEFT])
			ft_move_square(TRIGO, s_win);
		else if(s_win->game.input.key[SDL_SCANCODE_RIGHT])
			ft_move_square(ANTITRIGO, s_win);
	}
}

void			ft_read_the_map(t_my_win *s_win)
{
	int		y;
	int		x;
	char	*line;

	s_win->fd = open("mapwolf", O_RDWR);
	if (s_win->fd == -1)
		ft_putstr(strerror(errno));
	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		get_next_line((const int)s_win->fd, &line);
		x = 0;
		while (x < s_win->win_size.width / 20)
		{
			s_win->map[y][x] = ft_my_atoi(line[x]);
			x++;
		}
		y++;
	}
	close(s_win->fd);
}

int				ft_my_atoi(char c)
{
	int		nb;

	nb = c - '0';
	return (nb);
}
