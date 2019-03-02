/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_editor_seconde.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:14:56 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 17:58:33 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_save_the_map(t_my_win *s_win)
{
	int		y;
	int		x;

	s_win->fd = open("mapwolf", O_RDWR);
	if (s_win->fd == -1)
		ft_show_error_and_quit(s_win, "error in open the map\n");
	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		x = 0;
		while (x < s_win->win_size.width / 20)
		{
			write(s_win->fd, ft_itoa(s_win->map[y][x]), 1);
			x++;
		}
		write(s_win->fd, "\n", 1);
		y++;
	}
	close(s_win->fd);
	ft_free_the_map(s_win);
	s_win->input.quit = 1;
}
