/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:54:55 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 18:17:19 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_map_3d(t_my_win *s_win)
{
	int		x;
	int		y1;
	int		y2;
	double	projec_wall_height;

	s_win->win_index = map_3d;
	ft_clear_window(s_win, s_win->win_index);
	x = 0;
	while (x < s_win->win_size.width)
	{
		projec_wall_height = 20 / s_win->colision[x] * s_win->dis_project_plane;
		printf("size of the wall=%f et distance =%f\n", projec_wall_height, s_win->colision[x]);
		y1 = (int)((s_win->win_size.height / 2) - (projec_wall_height / 2));
		y2 = (int)((s_win->win_size.height / 2) + (projec_wall_height / 2));
		SDL_SetRenderDrawColor(s_win->renderer[s_win->win_index], 0, 255, 0, 0);
		SDL_RenderDrawLine(s_win->renderer[s_win->win_index], x, y1, x, y2);
		x++;
	}
	SDL_RenderPresent(s_win->renderer[s_win->win_index]);
}
