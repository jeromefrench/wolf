/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_draw_rectangle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:45:17 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/09 11:12:48 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_rectangle(t_my_rectangle s_rectangle, t_my_win *s_win,
int index)
{
	int			x;
	int			y;

	SDL_SetRenderDrawColor(s_win->renderer[index], 255, 255, 255, 0);
	y = s_rectangle.point.y;
	while (y < (s_rectangle.point.y + s_rectangle.size.height))
	{
		x = s_rectangle.point.x;
		while (x < s_rectangle.point.x + s_rectangle.size.height)
		{
			SDL_RenderDrawPoint(s_win->renderer[index], x, y);
			x++;
		}
		y++;
	}
}
