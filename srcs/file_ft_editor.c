/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:44:08 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/10 15:12:12 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_quit_map_editor(t_my_win *s_win)
{
	ft_quit(s_win, SUCESS);
}

void			ft_put_square_on_map(t_my_win *s_win, int index)
{
	ft_get_mouse_position(s_win);
	s_win->map[s_win->mouse_position.y / 20][s_win->mouse_position.x / 20] = 1;
	ft_clear_window(s_win, index);
	ft_draw_map(s_win, index);
	SDL_RenderPresent(s_win->renderer[index]);
	s_win->editor.input.mouse_clic = 0;
}

void			ft_square_follow_pointer(t_my_win *s_win)
{
	t_my_rectangle		s_rectangle;

	s_win->win_index = map_editor;
	ft_get_mouse_position(s_win);
	s_rectangle.point.x = s_win->mouse_position.x;
	s_rectangle.point.y = s_win->mouse_position.y;
	s_rectangle.size.height = 20;
	s_rectangle.size.width = 20;
	ft_clear_window(s_win, s_win->win_index);
	ft_draw_map(s_win, s_win->win_index);
	ft_draw_rectangle(s_rectangle, s_win, s_win->win_index);
	ft_put_text(s_win, "press S to save", 450, s_win->win_index);
	SDL_RenderPresent(s_win->renderer[s_win->win_index]);
	s_win->editor.input.mouse_move = 0;
}

void			ft_draw_map(t_my_win *s_win, int index)
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
				ft_draw_rectangle(s_rectangle, s_win, index);
			}
			x++;
		}
		y++;
	}
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
