/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_move_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:28:32 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/08 11:34:28 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


void			ft_init_square_pos(t_my_win *s_win)
{
	s_win->game.player_pos.x = 10;
	s_win->game.player_pos.y = 10;
	s_win->game.rect.point.x = s_win->game.player_pos.x;
	s_win->game.rect.point.y = s_win->game.player_pos.y;
	s_win->game.rect.size.height = 10;
	s_win->game.rect.size.width = 10;
	ft_draw_rectangle(s_win->game.rect, s_win);
}

void			ft_move_square(int move, t_my_win *s_win)
{
	double			angle_r;
	int x;
	int y;

	int test = (int)s_win->game.ray_angle % (int)360.00;
	printf("the angle =%d\n", (test));

	if(move == DOWN)
	{
		x = 0;
		y = -10;
	}

	else if(move == UP)
	{
		x = 0;
		y = 10;
	}
	else if(move == LEFT)
	{
		x = -10;
		y = 0;
	}
	else if(move == RIGHT)
	{
		x = 10;
		y = 0;
	}
	else
	{
		x = 0;
		y = 0;
	}

	angle_r = s_win->game.ray_angle * 3.14 / 180;
//int a;
//int	b;
//printf("La positon du joueur =%d\n",a = (int)((s_win->game.player_pos.x + (x * cos(angle_r)) + (y * -sin(angle_r)) ) / 20));
//printf("La positon du joueur =%d\n",b = (int)((s_win->game.player_pos.y + (x * sin(angle_r)) + (y *  cos(angle_r)) ) / 20));
//printf("La map =%d\n", s_win->map[b][a]);

	if (
	s_win->map 	[(int)((s_win->game.player_pos.y + (x * sin(angle_r)) + (y *  cos(angle_r)) ) / 20)]
				[(int)((s_win->game.player_pos.x + (x * cos(angle_r)) + (y * -sin(angle_r)) ) / 20)]
				!=  1
	)
	{
		s_win->game.player_pos.x += (x * cos(angle_r)) + (y * -sin(angle_r));
		s_win->game.player_pos.y += (x * sin(angle_r)) + (y *  cos(angle_r));
	}

	ft_clear_window(s_win);
	ft_draw_player(s_win);

	ft_ray_tracing(s_win, move);

	ft_draw_map(s_win);
	SDL_RenderPresent(s_win->renderer);

	s_win->game.input.key[SDL_SCANCODE_W] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_S] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_A] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_D] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_LEFT] = FALSE;
	s_win->game.input.key[SDL_SCANCODE_RIGHT] = FALSE;
}

void			ft_draw_player(t_my_win *s_win)
{
	t_my_rectangle	s_rectangle;
	int				x;
	int				y;


	s_rectangle.point = s_win->game.player_pos;
	s_rectangle.size.width = 10;
	s_rectangle.size.height = 10;



	SDL_SetRenderDrawColor(s_win->renderer, 0, 255, 255, 0);
	y = s_rectangle.point.y - (s_rectangle.size.height / 2);
	while (y < (s_rectangle.point.y + (s_rectangle.size.height / 2)))
	{
		x = s_rectangle.point.x - (s_rectangle.size.height / 2);
		while (x < s_rectangle.point.x + (s_rectangle.size.height / 2))
		{
			SDL_RenderDrawPoint(s_win->renderer, x, y);
			x++;
		}
		y++;
	}
}
