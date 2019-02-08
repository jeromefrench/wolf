/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:44:08 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/08 16:08:18 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_quit_map_editor(t_my_win *s_win)
{
	ft_quit(s_win, SUCESS);
}

void			ft_put_square_on_map(t_my_win *s_win)
{
	ft_get_mouse_position(s_win);
	s_win->map[s_win->mouse_position.y / 20][s_win->mouse_position.x / 20] = 1;
	ft_clear_window(s_win);
	ft_draw_map(s_win);
	SDL_RenderPresent(s_win->renderer[0]);
	s_win->editor.input.mouse_clic = 0;
}

void			ft_square_follow_pointer(t_my_win *s_win)
{
	t_my_rectangle		s_rectangle;

	ft_get_mouse_position(s_win);
	s_rectangle.point.x = s_win->mouse_position.x;
	s_rectangle.point.y = s_win->mouse_position.y;
	s_rectangle.size.height = 20;
	s_rectangle.size.width = 20;
	ft_clear_window(s_win);
	ft_draw_map(s_win);
	ft_draw_rectangle(s_rectangle, s_win);
	ft_put_text(s_win, "press S to save", 450);
	SDL_RenderPresent(s_win->renderer[0]);
	s_win->editor.input.mouse_move = 0;
}

void			ft_draw_map(t_my_win *s_win)
{
	int					x;
	int					y;
	t_my_rectangle		s_rectangle;

	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		x = 0;
		while (x < s_win->win_size.width / 20)
		{
			if (s_win->map[y][x] == 1)
			{
				s_rectangle.point.x = x * 20;
				s_rectangle.point.y = y * 20;
				s_rectangle.size.height = 20;
				s_rectangle.size.width = 20;
				ft_draw_rectangle(s_rectangle, s_win);
			}
			x++;
		}
		y++;
	}
}

void			ft_save_the_map(t_my_win *s_win)
{
	int		y;
	int		x;

	s_win->fd = open("mapwolf", O_RDWR);
	if (s_win->fd == -1)
		ft_putstr(strerror(errno));
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
	ft_display_menu(s_win);
}

void			ft_free_the_map(t_my_win *s_win)
{
	int		y;

	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		free(s_win->map[y]);
		y++;
	}
	free(s_win->map);
}
