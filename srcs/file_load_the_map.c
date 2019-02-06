/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load_the_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:37:57 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/06 13:00:11 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_launch_map(t_my_win *s_win)
{
	ft_create_window(s_win);
	ft_create_renderer(s_win);
	ft_clear_window(s_win);
	s_win->map = ft_init_map(s_win);
	ft_read_the_map(s_win);
	ft_draw_map(s_win);
	SDL_RenderPresent(s_win->renderer);
}

void			ft_read_the_map(t_my_win *s_win)
{
	int		y;
	int		x;
	char	*line;

	s_win->fd = open("mapwolf", O_RDWR);
	if (s_win->fd == -1)
		ft_putstr(strerror(errno));
	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		get_next_line((const int)s_win->fd, &line);
		x = 0;
		while (x < s_win->win_size.width / 20)
		{
			s_win->map[y][x] = ft_my_atoi(line[x]);
			x++;
		}
		y++;
	}
	close(s_win->fd);
}

int				ft_my_atoi(char c)
{
	int		nb;

	nb = c - '0';
	return (nb);
}
