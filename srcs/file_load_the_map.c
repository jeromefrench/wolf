/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load_the_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:37:57 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/03 10:35:03 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_launch_map_2d(t_my_win *s_win)
{
	s_win->win_index = map_2d;
	s_win->map = ft_init_map(s_win);
	ft_read_the_map(s_win);
	ft_create_window(s_win, s_win->win_index);
	ft_create_renderer(s_win, s_win->win_index);
	ft_clear_window(s_win, s_win->win_index);
	ft_draw_map(s_win, s_win->win_index);
	ft_init_square_pos(s_win);
	SDL_RenderPresent(s_win->renderer[s_win->win_index]);
}

void			ft_launch_map_3d(t_my_win *s_win)
{
	s_win->win_index = map_3d;
	s_win->game.ray_angle = 0;
	ft_create_window(s_win, s_win->win_index);
	ft_create_renderer(s_win, s_win->win_index);
	ft_clear_window(s_win, s_win->win_index);
	ft_ray_casting(s_win, NOTHING);
	ft_draw_map_3d(s_win);
}

void			ft_launch_map(t_my_win *s_win)
{
	s_win->win_index = menu;
	ft_quit_window(s_win, s_win->win_index);
	s_win->input.quit = 1;
	ft_launch_map_2d(s_win);
	ft_launch_map_3d(s_win);
	ft_event_loop_map(s_win);
}

t_xyz_point		ft_turn_vector(t_xyz_point vector, double angle)
{
	angle = angle * M_PI / 180;
	vector.a = (vector.a * cos(angle)) + (vector.b * sin(angle));
	vector.b = (vector.a * -sin(angle)) + (vector.b * cos(angle));
	return (vector);
}

void			ft_init_event(t_my_win *s_win)
{
	s_win->input.quit = FALSE;
	s_win->input.key[SDL_SCANCODE_ESCAPE] = FALSE;
	s_win->input.key[SDL_SCANCODE_W] = FALSE;
	s_win->input.key[SDL_SCANCODE_S] = FALSE;
	s_win->input.key[SDL_SCANCODE_A] = FALSE;
	s_win->input.key[SDL_SCANCODE_D] = FALSE;
	s_win->input.key[SDL_SCANCODE_C] = FALSE;
	s_win->input.key[SDL_SCANCODE_LEFT] = FALSE;
	s_win->input.key[SDL_SCANCODE_RIGHT] = FALSE;
	s_win->input.key[SDL_SCANCODE_DOWN] = FALSE;
	s_win->input.key[SDL_SCANCODE_UP] = FALSE;
	s_win->input.key[SDL_SCANCODE_RETURN] = FALSE;
	s_win->input.mouse_move = FALSE;
	s_win->input.mouse_clic = FALSE;
}

void			ft_update_event_map(t_my_win *s_win)
{
	SDL_Event		event;

	while (SDL_PollEvent(&event))
	{
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)
			s_win->input.quit = TRUE;
		else if (event.type == SDL_KEYDOWN)
			s_win->input.key[event.key.keysym.scancode] = TRUE;
		else if (event.type == SDL_MOUSEMOTION)
			s_win->input.mouse_move = TRUE;
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			s_win->input.mouse_clic = TRUE;
		SDL_Delay(1);
	}
}

void			ft_event_loop_map(t_my_win *s_win)
{
	ft_init_event(s_win);
	while (!s_win->input.quit)
	{
		ft_update_event_map(s_win);
		if (s_win->input.quit)
			ft_quit(s_win, SUCESS);
		else if (s_win->input.key[SDL_SCANCODE_ESCAPE])
			s_win->input.quit = TRUE;
		else if (s_win->input.key[SDL_SCANCODE_W])
			ft_move_square(UP, s_win);
		else if (s_win->input.key[SDL_SCANCODE_S])
			ft_move_square(DOWN, s_win);
		else if (s_win->input.key[SDL_SCANCODE_A])
			ft_move_square(LEFT, s_win);
		else if (s_win->input.key[SDL_SCANCODE_D])
			ft_move_square(RIGHT, s_win);
		else if (s_win->input.key[SDL_SCANCODE_LEFT])
			ft_move_square(TRIGO, s_win);
		else if (s_win->input.key[SDL_SCANCODE_RIGHT])
			ft_move_square(ANTITRIGO, s_win);
		else if (s_win->input.mouse_move)
			ft_pointer_moving_player(s_win);

	}
	ft_quit_window(s_win, s_win->win_index = map_3d);
	ft_quit_window(s_win, s_win->win_index = map_2d);
	ft_display_menu(s_win);
}

void		ft_pointer_moving_player(t_my_win *s_win)
{
			ft_get_mouse_position(s_win);
			if (s_win->mouse_position.x > s_win->last_mouse_position.x)
			{
				ft_move_square(TRIGO, s_win);
				s_win->last_mouse_position.x = s_win->mouse_position.x;
			}
			else if (s_win->mouse_position.x < s_win->last_mouse_position.x)
			{
				ft_move_square(ANTITRIGO, s_win);
				s_win->last_mouse_position.x = s_win->mouse_position.x;
			}
}
