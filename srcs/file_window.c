/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:22:43 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/08 16:05:52 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_clear_window(t_my_win *s_win)
{
	int		x;
	int		y;

	SDL_SetRenderDrawColor(s_win->renderer[0], 255, 0, 0, 0);
	y = 0;
	while (y < s_win->win_size.height)
	{
		x = 0;
		while (x < s_win->win_size.width)
		{
			SDL_RenderDrawPoint(s_win->renderer[0], x, y);
			x++;
		}
		y++;
	}
}

void			ft_create_window(t_my_win *s_win)
{
	s_win->win_size.width = 640;
	s_win->win_size.height = 480;
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
		ft_show_error_and_quit(s_win, SDL_GetError());
	s_win->window[0] = SDL_CreateWindow("Wolf", SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED, s_win->win_size.width, s_win->win_size.height,
SDL_WINDOW_SHOWN);
	if (s_win->window[0] == NULL)
		ft_show_error_and_quit(s_win, SDL_GetError());
	SDL_RaiseWindow(s_win->window[0]);
	if (TTF_Init() == -1)
	{
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n",
TTF_GetError());
		exit(EXIT_FAILURE);
	}
}
