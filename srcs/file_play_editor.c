/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_play_editor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:44:51 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/05 13:18:54 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"



int				**ft_init_play(t_my_win *s_win)
{
	int		**map;
	int		y;
	int		x;

	map = (int**)malloc(sizeof(int*) * (s_win->win_size.height / 20));
	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * (s_win->win_size.width / 20));
		while (x < s_win->win_size.width / 20)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}

void			ft_play(t_my_win *s_win)
{
	ft_create_window(s_win);
	ft_create_renderer(s_win);
	s_win->map = ft_init_play(s_win);
	ft_event_loop_editor(s_win);
}