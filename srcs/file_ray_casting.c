/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:09:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/09 16:35:45 by jchardin         ###   ########.fr       */
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
	int					j;

	ft_init_ray_casting(s_win, move, &s_ray, &s_line);
	s_ray.i = 0;
	j = 0;
	while (s_ray.i < (s_ray.angle_ouverture * 2))
	{
		s_ray.distance = 1;
		s_ray.colision = 0;
		while (s_ray.colision != 1)
		{
			ft_ray_casting_calcul(&s_ray, &s_line);
			s_ray.colision = ft_test_colision(s_win, s_line);
			if (s_ray.colision == 0)
				s_ray.distance += 1;
		}
		s_line.deux.a += s_win->game.player_pos.x;
		s_line.deux.b += s_win->game.player_pos.y;
		s_win->colision[j] = s_ray.distance;
		j++;
		SDL_SetRenderDrawColor(s_win->renderer[s_win->index], 0, 0, 0, 0);
		ft_put_the_line_third(s_win, &s_line);
		s_ray.i += s_ray.step;
	}
}
