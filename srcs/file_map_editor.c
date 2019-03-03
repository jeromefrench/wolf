/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:44:51 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/03 10:11:20 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_update_event_editor(t_my_win *s_win)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			s_win->input.quit = TRUE;
		else if (event.type == SDL_KEYDOWN)
			s_win->input.key[event.key.keysym.scancode] = TRUE;
		else if (event.type == SDL_MOUSEMOTION)
			s_win->input.mouse_move = TRUE;
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			s_win->input.mouse_clic = TRUE;
		SDL_Delay(3);
	}
}

void			ft_event_loop_editor(t_my_win *s_win)
{
	s_win->win_index = map_editor;
	ft_init_event(s_win);
	while (!s_win->input.quit)
	{
		ft_update_event_editor(s_win);
		if (s_win->input.quit)
			ft_quit(s_win, SUCESS);
		else if (s_win->input.key[SDL_SCANCODE_ESCAPE])
			s_win->input.quit = 1;
		else if (s_win->input.mouse_clic)
			ft_put_square_on_map(s_win, s_win->win_index);
		else if (s_win->input.mouse_move)
			ft_square_follow_pointer(s_win);
		else if (s_win->input.key[SDL_SCANCODE_S])
			ft_save_the_map(s_win);
	}
	s_win->win_index = map_editor;
	ft_quit_window(s_win, s_win->win_index);
	ft_display_menu(s_win);
}

void			ft_map_editor(t_my_win *s_win)
{
	s_win->win_index = map_editor;
	ft_create_window(s_win, s_win->win_index);
	ft_create_renderer(s_win, s_win->win_index);
	s_win->map = ft_init_map(s_win);
	ft_clear_window(s_win, s_win->win_index);
	ft_draw_map(s_win, s_win->win_index);
	SDL_RenderPresent(s_win->renderer[s_win->win_index]);
	ft_event_loop_editor(s_win);
}

int				**ft_init_map(t_my_win *s_win)
{
	int		**map;
	int		y;
	int		x;

	map = (int**)malloc(sizeof(int*) * (s_win->win_size.height / 20));
	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * (s_win->win_size.width / 20));
		while (x < s_win->win_size.width / 20)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}
