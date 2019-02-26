/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_ray_casting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 10:56:24 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/11 12:55:10 by jchardin         ###   ########.fr       */
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
		colision = TRUE;
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
