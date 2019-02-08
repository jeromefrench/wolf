/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:06:56 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/08 16:32:40 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_move_the_arrow_down(t_my_win *s_win)
{
	s_win->menu.arrow_h += 80;
	s_win->menu.input.key[SDL_SCANCODE_DOWN] = 0;
	ft_draw_menu(s_win);
}

void			ft_move_the_arrow_up(t_my_win *s_win)
{
	s_win->menu.arrow_h -= 80;
	s_win->menu.input.key[SDL_SCANCODE_UP] = 0;
	ft_draw_menu(s_win);
}

void			ft_launch_map_editor(t_my_win *s_win)
{
	s_win->index = 0;
	if (s_win->renderer[s_win->index] != NULL)
		SDL_DestroyRenderer(s_win->renderer[s_win->index]);
	if (s_win->window[s_win->index] != NULL)
		SDL_DestroyWindow(s_win->window[s_win->index]);
	TTF_Quit();
	s_win->menu.input.quit = 1;
	ft_map_editor(s_win);
}

void			ft_draw_menu(t_my_win *s_win)
{
	s_win->index = 0;
	ft_clear_window(s_win, s_win->index);
	ft_put_text(s_win, "Map Editor", 120);
	ft_put_text(s_win, "Load Map", 200);
	ft_load_bmp(s_win, s_win->index);
	SDL_RenderPresent(s_win->renderer[s_win->index]);
}
