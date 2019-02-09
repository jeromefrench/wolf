/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:23:38 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/09 12:23:53 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
			printf("%d ", s_win->map[y][x]);
			x++;
		}
		printf("\n");
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
