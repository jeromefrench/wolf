/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/03 18:50:11 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_clear_window(t_my_win *s_win)
{
	int		x;
	int		y;

	SDL_SetRenderDrawColor(s_win->renderer, 255, 0, 0, 0);
	y = 0;
	while (y < s_win->win_size.height)
	{
		x = 0;
		while (x < s_win->win_size.width)
		{
			SDL_RenderDrawPoint(s_win->renderer, x, y);
			x++;
		}
		y++;
	}
}

void			ft_create_window(t_my_win *s_win)
{
	s_win->win_size.width = 640;
	s_win->win_size.height = 480;
	if (0 != SDL_Init(SDL_INIT_EVERYTHING))
		ft_show_error_and_quit(s_win, SDL_GetError());
	s_win->window = SDL_CreateWindow("Wolf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, s_win->win_size.width, s_win->win_size.height, SDL_WINDOW_SHOWN);
	if (s_win->window == NULL)
		ft_show_error_and_quit(s_win, SDL_GetError());
	SDL_RaiseWindow(s_win->window); //met la fenetre au premier plan


if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}




}

void			ft_create_renderer(t_my_win *s_win)
{
	s_win->renderer = SDL_CreateRenderer(s_win->window, -1, SDL_RENDERER_ACCELERATED);
	if (s_win->renderer == NULL)
		ft_show_error_and_quit(s_win, SDL_GetError());
	//display sdl_RendererIn
}

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

void			ft_update_event(t_my_input *s_input)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			s_input->quit = SDL_TRUE;
		else if (event.type == SDL_KEYDOWN)
			s_input->key[event.key.keysym.scancode] = SDL_TRUE;
		else if (event.type == SDL_KEYUP)
			s_input->key[event.key.keysym.scancode] = SDL_FALSE;
		else if (event.type == SDL_MOUSEMOTION)
			s_input->mouse = 1;
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			s_input->mouse_clic = 1;
		SDL_Delay(30);
	}
}

void			ft_draw_rectangle(t_my_rectangle s_rectangle, t_my_win *s_win)
{
	int			x;
	int			y;

	SDL_SetRenderDrawColor(s_win->renderer, 255, 255, 255, 0);
	y = s_rectangle.point.y;
	while (y < s_rectangle.point.y + s_rectangle.size.height)
	{
		x = s_rectangle.point.x;
		while(x < s_rectangle.point.x + s_rectangle.size.height)
		{
			SDL_RenderDrawPoint(s_win->renderer, x, y);
			x++;
		}
		y++;
	}
}

void			ft_event_loop(t_my_input *s_input, t_my_win *s_win)
{
	while(!s_input->quit)
	{
		ft_update_event(s_input);
		if(s_input->key[SDL_SCANCODE_C])
		{
			printf("appui sur C\n");
			ft_clear_window(s_win);
			s_input->key[SDL_SCANCODE_C] = SDL_FALSE;
		}
		if (s_input->key[SDL_SCANCODE_ESCAPE])
		{
			ft_quit(s_win, SUCESS);
		}
		if (s_input->mouse_clic)
		{
			ft_get_mouse_position(s_win);
			s_win->map[s_win->mouse_position.y / 20] [s_win->mouse_position.x / 20] = 1;
			ft_clear_window(s_win);
			ft_draw_map(s_win);
			SDL_RenderPresent(s_win->renderer);
			s_input->mouse_clic = 0;
		}
		if (s_input->mouse)
		{
			t_my_rectangle		s_rectangle;

			ft_get_mouse_position(s_win);
			s_rectangle.point.x = s_win->mouse_position.x;
			s_rectangle.point.y = s_win->mouse_position.y;
			s_rectangle.size.height = 20;
			s_rectangle.size.width = 20;
			ft_clear_window(s_win);
			ft_draw_map(s_win);
			ft_draw_rectangle(s_rectangle, s_win);
			SDL_RenderPresent(s_win->renderer);
			s_input->mouse = 0;
		}
		SDL_Delay(20);
	}
}

void		ft_draw_map(t_my_win *s_win)
{
	int		x;
	int		y;
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
				ft_draw_rectangle(s_rectangle, s_win);
			}
			x++;
		}
		y++;
	}

}

int				**ft_init_map(t_my_win *s_win)
{
	int		**map;
	int		y;
	int		x;

	map = (int**)malloc(sizeof(int*) * (s_win->win_size.height / 20));
	y = 0;
	while (y < s_win->win_size.height / 20)
	{
		x = 0;
		map[y] = (int*)malloc(sizeof(int) * (s_win->win_size.width / 20));
		while (x < s_win->win_size.width / 20)
		{
			map[y][x] = 0;
			x++;
		}
		y++;
	}
	return (map);
}

void			ft_map_editor(t_my_win *s_win)
{
	t_my_input		s_input;

	ft_create_window(s_win);
	ft_create_renderer(s_win);
	printf("hello\n");
	s_win->map = ft_init_map(s_win);
	ft_event_loop(&s_input, s_win);
}

void			ft_display_menu(t_my_win *s_win)
{
	(void)s_win;
	
int quit = 0;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window * window = SDL_CreateWindow("SDL_ttf in SDL2",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,
        480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    TTF_Font * font = TTF_OpenFont("/Users/jchardin/wolf/films.icedeart.ttf", 25);
if(!font) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
}
    SDL_Color color = { 255, 255, 255, 0 };
    SDL_Surface * surface = TTF_RenderText_Solid(font,
        "Welcome to Gigi Labs", color);
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = { 0, 0, texW, texH };

    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = 1;
                break;
        }

        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_my_win	s_win;
	ft_display_menu(&s_win);
	//ft_map_editor(&s_win);
	return (SUCESS);
}
