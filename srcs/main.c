/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/01 16:51:58 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_my_win	s_win;

	//SDL_Surface *surface;

	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
		ft_show_error_and_quit(&s_win, SDL_GetError());

	s_win.window = SDL_CreateWindow("Wolf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

	SDL_RaiseWindow(s_win.window); //met la fenetre au premier plan
	if (s_win.window == NULL)
		ft_show_error_and_quit(&s_win, SDL_GetError());

	//surface = SDL_GetWindowSurface(window);
	//SDL_UpdateWindowSurface(window);

	s_win.renderer = SDL_CreateRenderer(s_win.window, -1, SDL_RENDERER_ACCELERATED);
	if (s_win.renderer == NULL)
		ft_show_error_and_quit(&s_win, SDL_GetError());

SDL_Event e;
for (;;) {
    SDL_PollEvent(&e);
    if (e.type == SDL_QUIT) {
        SDL_Log("Program quit after %i ticks", e.quit.timestamp);
	ft_quit(&s_win, SUCESS);
        break;
    }
}

	SDL_Delay(6000);
	ft_quit(&s_win, SUCESS);
	return (SUCESS);
}

