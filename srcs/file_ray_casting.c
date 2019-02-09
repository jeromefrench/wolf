/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:09:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/09 12:19:25 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_ray_casting(t_my_win *s_win, int angle)
{
	t_myputtheline	s_line;
	double			angle_r;
	double			angle_ouverture;
	double			angle_calcul_r;
	double			distance;
	double			x;
	double			y;
	double			angle_calcul;
	double			i;
	int				colision;
	int				j;
	double			step;

	angle_ouverture = 50;
	s_win->index = 0;
	if (angle == TRIGO)
		s_win->game.ray_angle += 5;
	else if (angle == ANTITRIGO)
		s_win->game.ray_angle -= 5;
	s_line.un.a = s_win->game.player_pos.x;
	s_line.un.b = s_win->game.player_pos.y;
	distance = 1;
	x = 0;
	y = distance;
	angle_r = s_win->game.ray_angle * 3.14 / 180;
	SDL_SetRenderDrawColor(s_win->renderer[s_win->index], 0, 0, 0, 0);
	angle_calcul = (180 - angle_ouverture) / 2;
	i = 0;
	step = (angle_ouverture * 2) / s_win->win_size.width;
	j = 0;
	while (i < (angle_ouverture * 2))
	{
		distance = 1;
		colision = 0;
		while (colision != 1)
		{
			angle_calcul = (180 - angle_ouverture + i) / 2;
			angle_calcul_r = angle_calcul * 3.14 / 180;
			x = cos(angle_calcul_r) * distance;
			y = sin(angle_calcul_r) * distance;
			s_line.deux.a = (x * cos(angle_r)) + (y * -sin(angle_r));
			s_line.deux.b = (x * sin(angle_r)) + (y * cos(angle_r));
			if (s_win->map[(int)((s_line.deux.b + s_win->game.player_pos.y) / 20)][(int)((s_line.deux.a + s_win->game.player_pos.x) / 20)] == 1)
				colision = 1;
			else
				distance += 1;
			if (s_line.deux.a + s_win->game.player_pos.x > (s_win->win_size.width - 1) || s_line.deux.a + s_win->game.player_pos.x < 0)
				colision = 1;
			if (s_line.deux.b + s_win->game.player_pos.y > (s_win->win_size.height - 1) || s_line.deux.b + s_win->game.player_pos.y < 0)
				colision = 1;
		}
		s_line.deux.a += s_win->game.player_pos.x;
		s_line.deux.b += s_win->game.player_pos.y;
		ft_put_the_line_third(s_win, &s_line);
		i += step;
		j++;
	}
}
