/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/04 16:43:58 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_get_mouse_position(t_my_win *s_win)
{
	int		x;
	int		y;

	SDL_PumpEvents();
	SDL_GetMouseState(&x, &y);
	if (x != 0 && y != 0)
		s_win->mouse_position.x = x;
	s_win->mouse_position.y = y;
	if (x != 0 && y != 0)
		printf("x=%d, y=%d\n", x, y);
}

void			ft_draw_rectangle(t_my_rectangle s_rectangle, t_my_win *s_win)
{
	int			x;
	int			y;

	SDL_SetRenderDrawColor(s_win->renderer, 255, 255, 255, 0);
	y = s_rectangle.point.y;
	while (y < (s_rectangle.point.y + s_rectangle.size.height))
	{
		x = s_rectangle.point.x;
		while (x < s_rectangle.point.x + s_rectangle.size.height)
		{
			SDL_RenderDrawPoint(s_win->renderer, x, y);
			x++;
		}
		y++;
	}
}

int				main(int argc, char **argv)
{
	t_my_win	s_win;

	(void)argc;
	(void)argv;
	ft_display_menu(&s_win);
	//ft_map_editor(&s_win);
	return (SUCESS);
}
