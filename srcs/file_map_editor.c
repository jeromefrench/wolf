/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:44:51 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/04 18:47:49 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_update_event(t_my_win *s_win)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			s_win->editor.input.quit = SDL_TRUE;
			s_win->menu.input.quit = SDL_TRUE;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			s_win->editor.input.key[event.key.keysym.scancode] = SDL_TRUE;
			s_win->menu.input.key[event.key.keysym.scancode] = SDL_TRUE;
		}
		else if (event.type == SDL_KEYUP)
		{
			s_win->editor.input.key[event.key.keysym.scancode] = SDL_FALSE;
			s_win->menu.input.key[event.key.keysym.scancode] = SDL_FALSE;
		}
		else if (event.type == SDL_MOUSEMOTION)
		{
			s_win->editor.input.mouse = 1;
			s_win->menu.input.mouse = 1;
		}
		else if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			s_win->editor.input.mouse_clic = 1;
			s_win->menu.input.mouse_clic = 1;
		}
		SDL_Delay(30);
	}
}

void			ft_event_loop(t_my_win *s_win)
{
	t_my_rectangle		s_rectangle;

	s_win->editor.input.key[SDL_SCANCODE_C] = SDL_FALSE;
	s_win->editor.input.quit = SDL_FALSE;
	s_win->editor.input.key[SDL_SCANCODE_ESCAPE] = 0;
	printf("event loop\n");
	while (!s_win->editor.input.quit)
	{
		ft_update_event(s_win);
		if (s_win->editor.input.key[SDL_SCANCODE_C])
		{
			printf("appui sur C\n");
			ft_clear_window(s_win);
			s_win->editor.input.key[SDL_SCANCODE_C] = SDL_FALSE;
		}
		if (s_win->editor.input.key[SDL_SCANCODE_ESCAPE])
		{
			printf("appui sur escape\n");
			ft_quit(s_win, SUCESS);
		}
		if (s_win->editor.input.mouse_clic)
		{
			printf("mouse clic\n");
			ft_get_mouse_position(s_win);
			s_win->map[s_win->mouse_position.y / 20][s_win->mouse_position.x / 20] = 1;
			ft_clear_window(s_win);
			ft_draw_map(s_win);
			SDL_RenderPresent(s_win->renderer);
			s_win->editor.input.mouse_clic = 0;
		}
		if (s_win->editor.input.mouse)
		{
			ft_get_mouse_position(s_win);
			s_rectangle.point.x = s_win->mouse_position.x;
			s_rectangle.point.y = s_win->mouse_position.y;
			s_rectangle.size.height = 20;
			s_rectangle.size.width = 20;
			ft_clear_window(s_win);
			ft_draw_map(s_win);
			ft_draw_rectangle(s_rectangle, s_win);
			SDL_RenderPresent(s_win->renderer);
			s_win->editor.input.mouse = 0;
		}
		SDL_Delay(20);
	}
}

void			ft_map_editor(t_my_win *s_win)
{
	ft_create_window(s_win);
	ft_create_renderer(s_win);
	printf("hello\n");
	s_win->map = ft_init_map(s_win);
	ft_event_loop(s_win);
}

void			ft_draw_map(t_my_win *s_win)
{
	int					x;
	int					y;
	t_my_rectangle		s_rectangle;

	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		x = 0;
		while (x < s_win->win_size.width / 20)
		{
			if (s_win->map[y][x] == 1)
			{
				s_rectangle.point.x = x * 20;
				s_rectangle.point.y = y * 20;
				s_rectangle.size.height = 20;
				s_rectangle.size.width = 20;
				ft_draw_rectangle(s_rectangle, s_win);
			}
			x++;
		}
		y++;
	}
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
