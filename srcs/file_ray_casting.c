/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:09:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/10 11:03:59 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_init_ray_casting(t_my_win *s_win, int move,
t_my_ray_casting *s_ray, t_myputtheline *s_line)
{
	s_win->index = 0;
	s_ray->angle_ouverture = 50;
	s_ray->distance = 1;
	s_ray->x = 0;
	s_ray->y = s_ray->distance;
	s_line->un.a = s_win->game.player_pos.x;
	s_line->un.b = s_win->game.player_pos.y;
	s_win->game.ray_angle += ft_init_angle(move);
	s_ray->ray_angle = s_win->game.ray_angle * 3.14 / 180;
	s_ray->angle_calcul = (180 - s_ray->angle_ouverture) / 2;
	s_ray->step = (s_ray->angle_ouverture * 2) / s_win->win_size.width;
}

void			ft_ray_casting_calcul(t_my_ray_casting *s_ray,
t_myputtheline *s_line)
{
	s_ray->angle_calcul = (180 - s_ray->angle_ouverture + s_ray->i) / 2;
	s_ray->angle_calcul = s_ray->angle_calcul * 3.14 / 180;
	s_ray->x = cos(s_ray->angle_calcul) * s_ray->distance;
	s_ray->y = sin(s_ray->angle_calcul) * s_ray->distance;
	s_line->deux.a = (s_ray->x * cos(s_ray->ray_angle)) +
(s_ray->y * -sin(s_ray->ray_angle));
	s_line->deux.b = (s_ray->x * sin(s_ray->ray_angle)) +
(s_ray->y * cos(s_ray->ray_angle));
}

void			ft_ray_casting(t_my_win *s_win, int move)
{
	t_my_ray_casting	s_ray;
	t_myputtheline		s_line;

	ft_init_ray_casting(s_win, move, &s_ray, &s_line);
	s_ray.i = 0;
	s_ray.j = 0;
	while (s_ray.i < (s_ray.angle_ouverture * 2))
	{
		s_ray.distance = 1;
		s_ray.colision = 0;
		while (s_ray.colision != 1)
		{
			ft_ray_casting_calcul(&s_ray, &s_line);
			if ((s_ray.colision = ft_test_colision(s_win, s_line)) == 0)
				s_ray.distance += 1;
		}
		s_line.deux.a += s_win->game.player_pos.x;
		s_line.deux.b += s_win->game.player_pos.y;
		s_win->colision[s_ray.j] = s_ray.distance *
cos((M_PI / 2) - s_ray.angle_calcul + 0.002);
		s_ray.j++;
		SDL_SetRenderDrawColor(s_win->renderer[s_win->index], 0, 0, 0, 0);
		ft_put_the_line_third(s_win, &s_line);
		s_ray.i += s_ray.step;
	}
}
