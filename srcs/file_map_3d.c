/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:54:55 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 14:37:40 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_map_3d(t_my_win *s_win)
{
	int		x;
	int		y1;
	int		y2;

	s_win->win_index = map_3d;


	double distance_to_projected_plane;

	distance_to_projected_plane = s_win->win_size.width / 2 /  tan(50 * M_PI / 180);

	ft_clear_window(s_win, s_win->win_index);
	x = 0;
	while (x < s_win->win_size.width)
	{

		double projected_slice_height = 20 / s_win->colision[x] * distance_to_projected_plane;


		y1 =(int) ((s_win->win_size.height / 2) - (projected_slice_height / 2));
		y2 =(int) ((s_win->win_size.height / 2) + (projected_slice_height / 2));





		SDL_SetRenderDrawColor(s_win->renderer[s_win->win_index], 0, 255, 0, 0); //floor
		SDL_RenderDrawLine(s_win->renderer[s_win->win_index], x, y1, x, y2);


		x++;
	}
	SDL_RenderPresent(s_win->renderer[s_win->win_index]);
}
