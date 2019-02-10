/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:54:55 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/10 08:54:45 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_map_2d(t_my_win *s_win)
{
	int		x;
	int		y;
	int		i;

	s_win->index = 1;
	x = 0;
	y = 0;

	ft_clear_window(s_win, s_win->index);
	while (x < s_win->win_size.width)
	{
		y = 0;
		i = 0;
		//printf("Le x=%d et la distance =%f\n", x, s_win->colision[x]);
		while (y < s_win->win_size.height)
		{
			if (y > ((s_win->win_size.height / 2) - (300 - s_win->colision[x])) &&
 				(y < ((s_win->win_size.height / 2) + (300 - s_win->colision[x]))))
			{
				SDL_SetRenderDrawColor(s_win->renderer[s_win->index], 0, 0, 255, 0);
			}
			else
			{
				SDL_SetRenderDrawColor(s_win->renderer[s_win->index], 255, 255, 255, 0);
			}
			SDL_RenderDrawPoint(s_win->renderer[s_win->index], x, y);
			y++;
		}
		x++;
	}
	SDL_RenderPresent(s_win->renderer[s_win->index]);
}
