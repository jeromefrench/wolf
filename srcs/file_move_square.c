/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_move_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:28:32 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/06 15:01:34 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void			ft_init_square_pos(t_my_win *s_win)
{
	s_win->game.square_pos.x = 0;
	s_win->game.square_pos.y = 0;
	s_win->game.rect.point.x = s_win->game.square_pos.x;
	s_win->game.rect.point.y = s_win->game.square_pos.y;
	s_win->game.rect.size.height = 10;
	s_win->game.rect.size.width = 10;
	ft_draw_rectangle(s_win->game.rect, s_win);
}

void			ft_move_square(int move, t_my_win *s_win)
{
	if(move == UP)
		s_win->game.square_pos.y -= 2;
	else if(move == DOWN)
		s_win->game.square_pos.y += 2;
	else if(move == LEFT)
		s_win->game.square_pos.x -= 2;
	else if(move == RIGHT)
		s_win->game.square_pos.x += 2;

	s_win->game.rect.point.x = s_win->game.square_pos.x;
	s_win->game.rect.point.y = s_win->game.square_pos.y;
	s_win->game.rect.size.height = 10;
	s_win->game.rect.size.width = 10;
	ft_clear_window(s_win);
	ft_draw_rectangle(s_win->game.rect, s_win);
	s_win->game.input.key[SDL_SCANCODE_W] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_S] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_A] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_D] = FALSE;
	ft_draw_map(s_win);
	SDL_RenderPresent(s_win->renderer);
}
