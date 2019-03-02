/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:09:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 12:12:53 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_init_ray_casting(t_my_win *s_win, int move,
t_my_ray_casting *s_ray, t_myputtheline *s_line)
{
	s_win->win_index = map_3d;
	s_ray->angle_ouverture = 50;
	s_ray->x = 0;  //       comprend pas
	s_ray->y = s_ray->distance;  //       comprend pas
	s_line->un.a = s_win->game.player_pos.x;
	s_line->un.b = s_win->game.player_pos.y;
	s_win->game.ray_angle += ft_init_angle(move);
	s_win->game.ray_angle_rad = s_win->game.ray_angle * M_PI / 180;
	s_ray->angle_calcul = (180 - s_ray->angle_ouverture) / 2;
	s_ray->step = (s_ray->angle_ouverture * 2) / s_win->win_size.width; //comprend pas le * 2
}

void			ft_ray_casting_calcul(t_my_ray_casting *s_ray, t_my_win *s_win)
{
	s_ray->angle_calcul = (180 - s_ray->angle_ouverture + s_ray->angle_ouverture_variable) / 2;
	s_ray->angle_calcul = s_ray->angle_calcul * M_PI / 180;
	s_ray->x = cos(s_ray->angle_calcul) * s_ray->distance;
	s_ray->y = sin(s_ray->angle_calcul) * s_ray->distance;
	s_ray->colision.x  = (s_ray->x * cos(s_win->game.ray_angle_rad)) + (s_ray->y * -sin(s_win->game.ray_angle_rad));
	s_ray->colision.y  = (s_ray->x * sin(s_win->game.ray_angle_rad)) + (s_ray->y * cos(s_win->game.ray_angle_rad));
}

void			ft_ray_casting(t_my_win *s_win, int move)
{
	t_my_ray_casting	s_ray;
	t_myputtheline		s_line;

	ft_init_ray_casting(s_win, move, &s_ray, &s_line);
	s_ray.angle_ouverture_variable = 0;
	s_ray.cmp = 0;
	while (s_ray.angle_ouverture_variable < (s_ray.angle_ouverture * 2))
	{
		s_ray.distance = 0;
		s_ray.colision_detected = FALSE;
		while (s_ray.colision_detected == FALSE)
		{
			ft_ray_casting_calcul(&s_ray, s_win);
			if ((s_ray.colision_detected = ft_test_colision(s_win, &s_ray)) == FALSE)
				s_ray.distance += 1;
		}
		s_line.deux.a = s_win->game.player_pos.x + s_ray.colision.x;
		s_line.deux.b = s_win->game.player_pos.y + s_ray.colision.y;
		//s_win->colision[s_ray.cmp] = s_ray.distance * cos((M_PI / 2) - s_ray.angle_calcul + 0.002);
		s_win->colision[s_ray.cmp] = s_ray.distance * cos((M_PI / 2) - s_ray.angle_calcul + 0.002);
		s_ray.cmp++;
		SDL_SetRenderDrawColor(s_win->renderer[s_win->win_index], 0, 0, 0, 0);
		ft_put_the_line_third(s_win, &s_line);
		s_ray.angle_ouverture_variable += s_ray.step;
	}
}
