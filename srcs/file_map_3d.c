/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:54:55 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 10:24:25 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_map_3d(t_my_win *s_win)
{
	int		x;
	int		y;
	int		i;

	s_win->win_index = map_3d;
	x = 0;
	while (x < s_win->win_size.width)
	{
		y = 0;
		i = 0;
		while (y < s_win->win_size.height)
		{
			if (y > ((s_win->win_size.height / 2) - (340 - s_win->colision[x])) && (y < ((s_win->win_size.height / 2) + (340 - s_win->colision[x]))))
				SDL_SetRenderDrawColor(s_win->renderer[s_win->win_index], 0, 0, 255, 0);
			else if (y > ((s_win->win_size.height / 2) - (340 - s_win->colision[x])))
				SDL_SetRenderDrawColor(s_win->renderer[s_win->win_index], 255, 0, 0, 0);
			else if (y < ((s_win->win_size.height / 2) + (340 - s_win->colision[x])))
				SDL_SetRenderDrawColor(s_win->renderer[s_win->win_index], 0, 255, 0, 0);
			SDL_RenderDrawPoint(s_win->renderer[s_win->win_index], x, y);
			y++;
		}
		x++;
	}
	SDL_RenderPresent(s_win->renderer[s_win->win_index]);
}
