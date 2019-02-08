/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:37:14 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/08 16:06:47 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_create_renderer(t_my_win *s_win)
{
	s_win->renderer[0] = SDL_CreateRenderer(s_win->window[0], -1,
SDL_RENDERER_ACCELERATED);
	if (s_win->renderer[0] == NULL)
		ft_show_error_and_quit(s_win, SDL_GetError());
}
