/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:44:51 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/10 15:11:16 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_update_event_editor(t_my_win *s_win)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			s_win->editor.input.quit = SDL_TRUE;
		else if (event.type == SDL_KEYDOWN)
			s_win->editor.input.key[event.key.keysym.scancode] = SDL_TRUE;
		else if (event.type == SDL_MOUSEMOTION)
			s_win->editor.input.mouse_move = 1;
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			s_win->editor.input.mouse_clic = 1;
		SDL_Delay(3);
	}
}

void			ft_init_event_editor(t_my_win *s_win)
{
	s_win->editor.input.key[SDL_SCANCODE_C] = FALSE;
	s_win->editor.input.key[SDL_SCANCODE_ESCAPE] = FALSE;
	s_win->editor.input.key[SDL_SCANCODE_S] = FALSE;
	s_win->editor.input.mouse_move = FALSE;
	s_win->editor.input.mouse_clic = FALSE;
	s_win->editor.input.quit = FALSE;
}

void			ft_event_loop_editor(t_my_win *s_win)
{
	s_win->win_index = map_editor;
	ft_init_event_editor(s_win);
	while (!s_win->editor.input.quit)
	{
		ft_update_event_editor(s_win);
		if (s_win->editor.input.key[SDL_SCANCODE_ESCAPE])
			ft_quit_map_editor(s_win);
		else if (s_win->editor.input.mouse_clic)
			ft_put_square_on_map(s_win, s_win->win_index);
		else if (s_win->editor.input.mouse_move)
			ft_square_follow_pointer(s_win);
		else if (s_win->editor.input.key[SDL_SCANCODE_S])
			ft_save_the_map(s_win);
		SDL_Delay(20);
	}
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
