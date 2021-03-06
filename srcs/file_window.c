/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:22:43 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/11 11:05:18 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_clear_window(t_my_win *s_win, int index)
{
	int		x;
	int		y;

	SDL_SetRenderDrawColor(s_win->renderer[index], 255, 0, 0, 0);
	y = 0;
	while (y < s_win->win_size.height)
	{
		x = 0;
		while (x < s_win->win_size.width)
		{
			SDL_RenderDrawPoint(s_win->renderer[index], x, y);
			x++;
		}
		y++;
	}
}

void			ft_create_window(t_my_win *s_win, int index)
{
	s_win->win_size.width = 640;
	s_win->win_size.height = 480;
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
		ft_show_error_and_quit(s_win, SDL_GetError());
	s_win->window[index] = SDL_CreateWindow("Wolf", SDL_WINDOWPOS_CENTERED,
SDL_WINDOWPOS_CENTERED, s_win->win_size.width, s_win->win_size.height,
SDL_WINDOW_SHOWN);
	if (s_win->window[index] == NULL)
		ft_show_error_and_quit(s_win, "error in create window\n");
	SDL_RaiseWindow(s_win->window[index]);
	if (TTF_Init() == -1)
		ft_show_error_and_quit(s_win, "error in init ttf\n");
}
