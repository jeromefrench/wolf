/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:09:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/09 15:03:19 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				ft_ray_out_of_screen(t_my_win *s_win, t_myputtheline s_line)
{
	int		colision;

	colision = 0;
	if (s_line.deux.a + s_win->game.player_pos.x > (s_win->win_size.width -
1) || s_line.deux.a + s_win->game.player_pos.x < 0)
		colision = 1;
	if (s_line.deux.b + s_win->game.player_pos.y > (s_win->win_size.height -
1) || s_line.deux.b + s_win->game.player_pos.y < 0)
		colision = 1;
	return (colision);
}

int				ft_test_ray_colision(t_my_win *s_win, t_myputtheline s_line)
{
	int		colision;

	if (s_win->map[(int)((s_line.deux.b + s_win->game.player_pos.y) / 20)]
[(int)((s_line.deux.a + s_win->game.player_pos.x) / 20)] == 1)
		colision = 1;
	else
		colision = 0;
	return (colision);
}

int				ft_test_colision(t_my_win *s_win, t_myputtheline s_line)
{
	if (ft_test_ray_colision(s_win, s_line))
		return (1);
	if (ft_ray_out_of_screen(s_win, s_line))
		return (1);
	return (0);
}

int				ft_init_angle(int move)
{
	int		angle;
	if (move == TRIGO)
		angle = 5;
	else if (move == ANTITRIGO)
		angle = -5;
	else
		angle = 0;
	return (angle);
}

void			ft_ray_casting(t_my_win *s_win, int move)
{
	double			distance;
	double			x;
	double			y;
	t_myputtheline	s_line;
	int				colision;
	double			step;
	double			i;

	double			angle_ouverture;
	double			ray_angle;
	double			angle_calcul;



	s_win->index = 0;
	angle_ouverture = 50;
	distance = 1;
	x = 0;
	y = distance;


	s_line.un.a = s_win->game.player_pos.x;
	s_line.un.b = s_win->game.player_pos.y;


	s_win->game.ray_angle += ft_init_angle(move);
	ray_angle = s_win->game.ray_angle * 3.14 / 180;
	

	angle_calcul = (180 - angle_ouverture) / 2;
	step = (angle_ouverture * 2) / s_win->win_size.width;

	i = 0;
	while (i < (angle_ouverture * 2))
	{
		distance = 1;
		colision = 0;
		while (colision != 1)
		{
			angle_calcul = (180 - angle_ouverture + i) / 2;
			angle_calcul = angle_calcul * 3.14 / 180;


			x = cos(angle_calcul) * distance;
			y = sin(angle_calcul) * distance;


			s_line.deux.a = (x * cos(ray_angle)) + (y * -sin(ray_angle));
			s_line.deux.b = (x * sin(ray_angle)) + (y * cos(ray_angle));

			colision = ft_test_colision(s_win, s_line);
			if (colision == 0)
				distance += 1;
		}
		s_line.deux.a += s_win->game.player_pos.x;
		s_line.deux.b += s_win->game.player_pos.y;
		SDL_SetRenderDrawColor(s_win->renderer[s_win->index], 0, 0, 0, 0);
		ft_put_the_line_third(s_win, &s_line);
		i += step;
	}
}
