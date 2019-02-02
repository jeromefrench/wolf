/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/02 15:09:49 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_clear_window(t_my_win *s_win)
{
	int		x;
	int		y;

	SDL_SetRenderDrawColor(s_win->renderer, 0, 0, 0, 0);
	y = 0;
	while (y < s_win->win_size.height)
	{
		x = 0;
		while (x < s_win->win_size.width)
		{
			SDL_RenderDrawPoint(s_win->renderer, x, y);
			x++;
		}
		y++;
	}
	SDL_RenderPresent(s_win->renderer);
}


void			ft_create_window(t_my_win *s_win)
{
	s_win->win_size.width = 640;
	s_win->win_size.height = 480;
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
		ft_show_error_and_quit(s_win, SDL_GetError());
	s_win->window = SDL_CreateWindow("Wolf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, s_win->win_size.width, s_win->win_size.height, SDL_WINDOW_SHOWN);
	if (s_win->window == NULL)
		ft_show_error_and_quit(s_win, SDL_GetError());
	SDL_RaiseWindow(s_win->window); //met la fenetre au premier plan
}

void			ft_create_renderer(t_my_win *s_win)
{
	s_win->renderer = SDL_CreateRenderer(s_win->window, -1, SDL_RENDERER_ACCELERATED);
	if (s_win->renderer == NULL)
		ft_show_error_and_quit(s_win, SDL_GetError());
}

void			ft_get_mouse_position(void)
{
	int		x;
	int		y;

	SDL_PumpEvents();
	SDL_GetMouseState(&x, &y);
	if (x != 0 && y != 0)
	printf("mmouse x=%d, y=%d\n", x, y);
}

void			ft_update_event(t_my_input *s_input)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			s_input->quit = SDL_TRUE;
		else if (event.type == SDL_KEYDOWN)
			s_input->key[event.key.keysym.scancode] = SDL_TRUE;
		else if (event.type == SDL_KEYUP)
			s_input->key[event.key.keysym.scancode] = SDL_FALSE;
	}
}

void			ft_draw_rectangle(t_my_rectangle s_rectangle, t_my_win *s_win)
{
	int			x;
	int			y;

	SDL_SetRenderDrawColor(s_win->renderer, 255, 255, 255, 0);
	y = s_rectangle.point.y;
	while (y < s_rectangle.point.y + s_rectangle.size.height)
	{
		x = s_rectangle.point.x;
		while(x < s_rectangle.point.x + s_rectangle.size.height)
		{
			SDL_RenderDrawPoint(s_win->renderer, x, y);
			x++;
		}
		y++;
	}
	SDL_RenderPresent(s_win->renderer);
}

void			ft_event_loop(t_my_input *s_input, t_my_win *s_win)
{
	t_my_rectangle		s_rectangle;
	s_rectangle.point.x = 11;
	s_rectangle.point.y = 11;
	s_rectangle.size.height = 50;
	s_rectangle.size.width = 50;
	while(!s_input->quit)
	{
		ft_update_event(s_input);
		if(s_input->key[SDL_SCANCODE_A])
		{
			printf("appui sur A\n");
			ft_draw_rectangle(s_rectangle, s_win);
			s_input->key[SDL_SCANCODE_A] = SDL_FALSE;
		}
		if(s_input->key[SDL_SCANCODE_C])
		{
			printf("appui sur C\n");
			ft_clear_window(s_win);
			s_input->key[SDL_SCANCODE_C] = SDL_FALSE;
		}
		SDL_Delay(20);
	}
}

void			ft_map_editor(t_my_win *s_win)
{
	ft_create_window(s_win);
	ft_create_renderer(s_win);
	SDL_SetRenderDrawColor(s_win->renderer, 255, 255, 255, 0);
	printf("hello\n");
	SDL_RenderDrawPoint(s_win->renderer, 5, 5);
	SDL_RenderPresent(s_win->renderer);
	ft_clear_window(s_win);


	t_my_input		s_input;
	ft_event_loop(&s_input, s_win);


	//ft_event_loop(s_win);
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_my_win	s_win;

	ft_map_editor(&s_win);
	return (SUCESS);
}
