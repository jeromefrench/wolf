/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ray_casting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:09:13 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/03 16:52:05 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_init_ray_casting(t_my_win *s_win, int move,
t_my_ray_casting *s_ray, t_myputtheline *s_line)
{
	s_win->win_index = map_3d;
	s_ray->angle_ouverture = 50;
	s_line->un.a = s_win->game.player_pos.x;
	s_line->un.b = s_win->game.player_pos.y;
	s_win->game.ray_angle += ft_init_angle(move);
	s_win->game.ray_angle_rad = s_win->game.ray_angle * M_PI / 180;
	s_ray->angle_calcul = (180 - s_ray->angle_ouverture) / 2;
	s_ray->step = s_ray->angle_ouverture / s_win->win_size.width;
	s_win->dis_project_plane = s_win->win_size.width / 2 / tan(s_ray->angle_ouverture * M_PI / 180);
	s_ray->angle_ouverture_variable = 0;
	s_ray->cmp = 0;
}

void			ft_ray_casting_calcul(t_my_ray_casting *s_ray, t_my_win *s_win)
{
	s_ray->x = cos(s_ray->angle_calcul_rad) * s_ray->distance;
	s_ray->y = sin(s_ray->angle_calcul_rad) * s_ray->distance;
	s_ray->colision.x = (s_ray->x * cos(s_win->game.ray_angle_rad)) + (s_ray->y * -sin(s_win->game.ray_angle_rad));
	s_ray->colision.y = (s_ray->x * sin(s_win->game.ray_angle_rad)) + (s_ray->y * cos(s_win->game.ray_angle_rad));
	s_win->game.colision.x = s_win->game.player_pos.x + s_ray->colision.x;
	s_win->game.colision.y = s_win->game.player_pos.y + s_ray->colision.y;
}

void			ft_init_dda(t_my_win *s_win, t_my_dda *dda_horizontal, t_my_dda *dda_vertical, t_my_ray_casting	*s_ray)
{
	double		alpha;

	alpha = s_ray->angle_calcul_rad;
	//horizontal
	dda_horizontal->offset.y = s_win->game.player_pos.y % s_win->division;
	dda_horizontal->offset.x = dda_horizontal->offset.y / tan(alpha);
	dda_horizontal->distance_offset = sqrt(dda_horizontal->offset.x * dda_horizontal->offset.x
			+ dda_horizontal->offset.y + dda_horizontal->offset.y);
	dda_horizontal->delta.y = s_win->division;
	dda_horizontal->delta.x = dda_horizontal->delta.y / tan(alpha);

	//vertical
	dda_vertical->offset.x = s_win->division - (s_win->game.player_pos.x % s_win->division);
	dda_vertical->offset.y = tan(alpha) * dda_vertical->offset.x;
	dda_vertical->distance_offset = sqrt(dda_vertical->offset.x * dda_vertical->offset.x
			+ dda_vertical->offset.y + dda_vertical->offset.y);
	dda_vertical->delta.x = s_win->division;
	dda_vertical->delta.y = tan(alpha) * dda_vertical->delta.x;
}

void			ft_vertical_intercept(int *cmp)
{


}

void			ft_ray_casting(t_my_win *s_win, int move)
{
	t_my_ray_casting	s_ray;
	t_myputtheline		s_line;
	t_my_dda			dda_horizontal;
	t_my_dda			dda_vertical;
	int 				cmp;

	ft_init_ray_casting(s_win, move, &s_ray, &s_line);
	while (s_ray.angle_ouverture_variable < s_ray.angle_ouverture)
	{
		s_ray.distance = 0;
		s_ray.colision_detected = FALSE;
		s_ray.angle_calcul = (180 - s_ray.angle_ouverture + s_ray.angle_ouverture_variable) / 2;
		s_ray.angle_calcul_rad = s_ray.angle_calcul * M_PI / 180;
		cmp = 0;
		ft_init_dda(s_win, &dda_horizontal, &dda_vertical, &s_ray);
		while (s_ray.colision_detected == FALSE)
		{
			if (dda_vertical.distance_offset < dda_horizontal.distance_offset)
			{
				ft_vertical_intercept(&cmp);
				ft_ray_casting_calcul(&s_ray, s_win);
				if ((s_ray.colision_detected = ft_test_colision(s_win)) == FALSE)
				{
					ft_horizontal_intercept();
					ft_ray_casting_calcul(&s_ray, s_win);
					s_ray.colision_detected = ft_test_colision(s_win);
				}
				cmp++;
			}
			else
			{
				ft_horizontal_intercept();
				ft_ray_casting_calcul(&s_ray, s_win);
				if ((s_ray.colision_detected = ft_test_colision(s_win)) == FALSE)
				{
					ft_vertical_intercept();
					ft_ray_casting_calcul(&s_ray, s_win);
					s_ray.colision_detected = ft_test_colision(s_win);
				}
				cmp++;
			}
		}
		s_win->colision[s_ray.cmp] = s_ray.y;
		s_ray.cmp++;
		//printf("=%d\n",s_ray.cmp);
		//printf("=%f\n",s_win->colision[s_ray.cmp]);

		SDL_SetRenderDrawColor(s_win->renderer[s_win->win_index], 0, 0, 0, 0);
		ft_draw_line(s_win, &s_line);
		s_ray.angle_ouverture_variable += s_ray.step;
	}
}
