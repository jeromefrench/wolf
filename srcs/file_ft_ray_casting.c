/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_ray_casting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 10:56:24 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 13:09:55 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


int				ft_test_colision(t_my_win *s_win)
{
	int		y;
	int		x;

	if (s_win->game.colision.x > (s_win->win_size.width -1))
		return (TRUE);
	if (s_win->game.colision.x < 0)
		return (TRUE);
	if (s_win->game.colision.y > (s_win->win_size.height -1))
		return (TRUE);
	if (s_win->game.colision.y < 0)
		return (TRUE);
	y = (int)((s_win->game.colision.y) / 20);
	x = (int)((s_win->game.colision.x) / 20);
	if (s_win->map[y][x] == 1)
		return (TRUE);
	return (FALSE);
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
