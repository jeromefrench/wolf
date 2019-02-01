/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:22:40 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/01 13:54:33 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	SDL_Window *window;
	SDL_Surface *screen;
	if (0 != SDL_Init(SDL_INIT_VIDEO))
		ft_quit_error("The first message:");
	window = SDL_CreateWindow("Wolf", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
	//SDL_UpdateWindowSurface(window);
	SDL_Delay(3000);
	SDL_Quit();
	return (SUCESS);
}

void	ft_quit_error(char *my_message)
{
	perror(my_message);
	ft_putstr("\nThe seconde message :");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
    SDL_Quit();
	exit(FAILURE);
}
