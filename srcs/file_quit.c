/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:50:48 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/03 17:04:31 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf3d.h"

void	ft_show_error_and_quit(t_my_win *s_win, const char *my_message)
{
	perror(my_message);
	ft_putstr("\nThe seconde message :");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	ft_quit(s_win, FAILURE);
}

void	ft_quit(t_my_win *s_win, int status)
{
	if (s_win->renderer != NULL)
		SDL_DestroyRenderer(s_win->renderer);
	if (s_win->window != NULL)
		SDL_DestroyWindow(s_win->window);
	TTF_Quit();
	SDL_Quit();
	exit(status);
}



