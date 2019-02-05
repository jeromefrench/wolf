/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mouse_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:47:18 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/05 13:04:40 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_get_mouse_position(t_my_win *s_win)
{
	int		x;
	int		y;

	SDL_PumpEvents();
	SDL_GetMouseState(&x, &y);
	s_win->mouse_position.x = x;
	s_win->mouse_position.y = y;
}
