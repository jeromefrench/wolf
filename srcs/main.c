/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/01 19:02:07 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void			ft_create_window(t_my_win *s_win)
{
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
		ft_show_error_and_quit(s_win, SDL_GetError());
	s_win->window = SDL_CreateWindow("Wolf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
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

void			ft_event_loop(t_my_win *s_win)
{
	while(1)
	{
		SDL_PollEvent(&(s_win->event));
		if(s_win->event.type == SDL_QUIT)
			ft_quit(s_win, SUCESS);
		if(s_win->event.key.keysym.sym == SDLK_ESCAPE)
			ft_quit(s_win, SUCESS);
		if(s_win->event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (s_win->event.button.button == SDL_BUTTON_LEFT)
				printf("clic\n");
		}
		printf("bla\n");
	}
}

void			ft_map_editor(t_my_win *s_win)
{
	ft_create_window(s_win);
	ft_create_renderer(s_win);
	SDL_SetRenderDrawColor(s_win->renderer, 255, 255, 255, 255);


	SDL_RenderDrawPoint(s_win->renderer, 10, 10);
	SDL_RenderPresent(s_win->renderer);





	ft_event_loop(s_win);


}



int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_my_win	s_win;

	ft_map_editor(&s_win);

	return (SUCESS);
}

