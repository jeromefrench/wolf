/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/01/29 14:48:21 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./wolf3d.h"

int main(int argc, char **argv)
{
	t_win *wn;

	wn = malloc(sizeof(wn));
	SDL_Init(SDL_INIT_EVERYTHING);

	wn->wind = SDL_CreateWindow("Wolf", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	wn->surface = SDL_GetWindowSurface(wn->wind);
	SDL_UpdateWindowSurface(wn->wind);
	SDL_Delay(3000);
	return (0);
}
