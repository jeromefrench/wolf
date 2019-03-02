/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:39:44 by jchardin          #+#    #+#             */
/*   Updated: 2019/03/02 15:22:51 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_display_menu(t_my_win *s_win)
{
	s_win->win_index = menu;
	s_win->menu.arrow_h = 120;
	ft_create_window(s_win, s_win->win_index);
	ft_create_renderer(s_win, s_win->win_index);
	ft_draw_menu(s_win);
	ft_event_loop_menu(s_win);
}

void			ft_init_event_menu(t_my_win *s_win)
{
	s_win->menu.input.quit = FALSE;
	s_win->menu.input.key[SDL_SCANCODE_DOWN] = FALSE;
	s_win->menu.input.key[SDL_SCANCODE_UP] = FALSE;
	s_win->menu.input.key[SDL_SCANCODE_RETURN] = FALSE;
	s_win->menu.input.key[SDL_SCANCODE_ESCAPE] = FALSE;
	s_win->menu.input.mouse_move = FALSE;
	s_win->menu.input.mouse_clic = FALSE;
}

void			ft_update_event_menu(t_my_win *s_win)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			s_win->menu.input.quit = SDL_TRUE;
		else if (event.type == SDL_KEYDOWN)
			s_win->menu.input.key[event.key.keysym.scancode] = SDL_TRUE;
		SDL_Delay(3);
	}
}

void			ft_event_loop_menu(t_my_win *s_win)
{
	ft_init_event_menu(s_win);
	while (!s_win->menu.input.quit)
	{
		ft_update_event_menu(s_win);
		if (s_win->menu.input.quit)
			ft_quit(s_win, SUCESS);
		else if (s_win->menu.input.key[SDL_SCANCODE_ESCAPE])
			ft_quit(s_win, SUCESS);
		else if (s_win->menu.input.key[SDL_SCANCODE_DOWN] &&
s_win->menu.arrow_h <= 120)
			ft_move_the_arrow_down(s_win);
		else if (s_win->menu.input.key[SDL_SCANCODE_UP] &&
s_win->menu.arrow_h >= 200)
			ft_move_the_arrow_up(s_win);
		else if (s_win->menu.input.key[SDL_SCANCODE_RETURN] &&
s_win->menu.arrow_h == 120)
			ft_launch_map_editor(s_win);
		else if (s_win->menu.input.key[SDL_SCANCODE_RETURN] &&
s_win->menu.arrow_h == 200)
			ft_launch_map(s_win);
	}
}

void			ft_put_text(t_my_win *s_win, char *str, int place, int index)
{
	t_my_put_smth		text;

	text.color.r = 255;
	text.color.g = 255;
	text.color.b = 255;
	text.color.a = 0;
	text.text_w = 0;
	text.text_h = 0;
	TTF_Init();
	text.font = TTF_OpenFont("./media/films.icedeart.ttf", 35);
	if (!text.font)
		ft_putstr("error\n");
	text.surface = TTF_RenderText_Solid(text.font, str, text.color);
	text.texture = SDL_CreateTextureFromSurface(s_win->renderer[index],
text.surface);
	SDL_QueryTexture(text.texture, NULL, NULL, &(text.text_w), &(text.text_h));
	text.dstrect.x = 250;
	text.dstrect.y = place;
	text.dstrect.w = text.text_w;
	text.dstrect.h = text.text_h;
	SDL_RenderCopy(s_win->renderer[index], text.texture, NULL, &(text.dstrect));
}
