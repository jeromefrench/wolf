/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ft_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 19:06:56 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 15:57:55 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_move_the_arrow_down(t_my_win *s_win)
{
	s_win->menu.arrow_h += 80;
	s_win->input.key[SDL_SCANCODE_DOWN] = 0;
	ft_draw_menu(s_win);
}

void			ft_move_the_arrow_up(t_my_win *s_win)
{
	s_win->menu.arrow_h -= 80;
	s_win->input.key[SDL_SCANCODE_UP] = 0;
	ft_draw_menu(s_win);
}

void			ft_launch_map_editor(t_my_win *s_win)
{
	s_win->win_index = menu;
	ft_quit_window(s_win, s_win->win_index);
	s_win->input.quit = 1;
	ft_map_editor(s_win);
}

void			ft_draw_menu(t_my_win *s_win)
{
	s_win->win_index = menu;
	ft_clear_window(s_win, s_win->win_index);
	ft_put_text(s_win, "Map Editor", 120, s_win->win_index);
	ft_put_text(s_win, "Load Map", 200, s_win->win_index);
	ft_load_bmp(s_win, s_win->win_index);
	SDL_RenderPresent(s_win->renderer[s_win->win_index]);
}

void			ft_load_bmp(t_my_win *s_win, int index)
{
	t_my_put_smth		bmp;

	bmp.text_w = 0;
	bmp.text_h = 0;
	bmp.surface = NULL;
	bmp.texture = NULL;
	bmp.surface = SDL_LoadBMP("./media/untitled.bmp");
	bmp.texture = SDL_CreateTextureFromSurface(s_win->renderer[index],
bmp.surface);
	SDL_FreeSurface(bmp.surface);
	SDL_QueryTexture(bmp.texture, NULL, NULL, &(bmp.text_w), &(bmp.text_h));
	bmp.dstrect.x = 200;
	bmp.dstrect.y = s_win->menu.arrow_h;
	bmp.dstrect.w = bmp.text_w;
	bmp.dstrect.h = bmp.text_h;
	SDL_RenderCopy(s_win->renderer[index], bmp.texture, NULL, &(bmp.dstrect));
}
