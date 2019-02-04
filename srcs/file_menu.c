/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:39:44 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/04 17:41:09 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_display_menu(t_my_win *s_win)
{
	t_my_input		s_input;

	s_win->menu.arrow_h = 120;
	ft_create_window(s_win);
	ft_create_renderer(s_win);
	ft_event_loop_menu(&s_input, s_win);
}

void			ft_event_loop_menu(t_my_input *s_input, t_my_win *s_win)
{
	ft_draw_menu(s_win);
	while (!s_input->quit)
	{
		ft_update_event(s_input);
		if (s_input->key[SDL_SCANCODE_ESCAPE])
			ft_quit(s_win, SUCESS);
		else if (s_input->key[SDL_SCANCODE_DOWN] && s_win->menu.arrow_h <= 120)
		{
			s_win->menu.arrow_h += 80;
			s_input->key[SDL_SCANCODE_DOWN] = 0;
			ft_draw_menu(s_win);
		}
		else if (s_input->key[SDL_SCANCODE_UP] && s_win->menu.arrow_h >= 200)
		{
			s_win->menu.arrow_h -= 80;
			s_input->key[SDL_SCANCODE_UP] = 0;
			ft_draw_menu(s_win);
		}
		else if (s_input->key[SDL_SCANCODE_RETURN] && s_win->menu.arrow_h == 120)
		{
			if (s_win->renderer != NULL)
				SDL_DestroyRenderer(s_win->renderer);
			if (s_win->window != NULL)
				SDL_DestroyWindow(s_win->window);
			TTF_Quit();
			s_input->quit = 1;
			ft_map_editor(s_win);
		}
		else if (s_input->key[SDL_SCANCODE_RETURN] && s_win->menu.arrow_h == 200)
		{
		}
		SDL_Delay(3);
	}
}

void			ft_draw_menu(t_my_win *s_win)
{
	ft_clear_window(s_win);
	ft_put_text(s_win, "Map Editor", 120);
	ft_put_text(s_win, "Load Map", 200);
	ft_load_bmp(s_win);
	SDL_RenderPresent(s_win->renderer);
}

void			ft_put_text(t_my_win *s_win, char *str, int place)
{
	SDL_Color		color;
	int				text_w;
	int				text_h;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Rect		dstrect;
	TTF_Font		*font;

	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 0;
	text_w = 0;
	text_h = 0;
	TTF_Init();
	font = TTF_OpenFont("/Users/jchardin/wolf/films.icedeart.ttf", 35);
	if (!font)
	{
		printf("TTF_OpenFont: %s\n", TTF_GetError());
	}
	surface = TTF_RenderText_Solid(font, str, color);
	texture = SDL_CreateTextureFromSurface(s_win->renderer, surface);
	SDL_QueryTexture(texture, NULL, NULL, &text_w, &text_h);
	dstrect.x = 250;
	dstrect.y = place;
	dstrect.w = text_w;
	dstrect.h = text_h;
	SDL_RenderCopy(s_win->renderer, texture, NULL, &(dstrect));
}

void			ft_load_bmp(t_my_win *s_win)
{
	int				text_w;
	int				text_h;
	SDL_Surface		*tmp;
	SDL_Texture		*texture3;
	SDL_Rect		dstrect3;

	text_w = 0;
	text_h = 0;
	tmp = NULL;
	texture3 = NULL;
	tmp = SDL_LoadBMP("/Users/jchardin/wolf/untitled.bmp");
	texture3 = SDL_CreateTextureFromSurface(s_win->renderer, tmp);
	SDL_FreeSurface(tmp);
	SDL_QueryTexture(texture3, NULL, NULL, &(text_w), &(text_h));
	dstrect3.x = 200;
	dstrect3.y = s_win->menu.arrow_h;
	dstrect3.w = text_w;
	dstrect3.h = text_h;
	SDL_RenderCopy(s_win->renderer, texture3, NULL, &(dstrect3));
}
