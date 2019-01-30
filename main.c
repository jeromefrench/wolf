/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/30 10:54:25 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./wolf3d.h"

int main(int argc, char **argv)
{
	SDL_Window *window;
	SDL_Surface *screen;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Wolf", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
	SDL_UpdateWindowSurface(window);
	SDL_Delay(3000);
	return (0);
}
