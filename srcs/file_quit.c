/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:50:48 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/10 15:47:13 by jchardin         ###   ########.fr       */
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
	(void)s_win;
//	if (s_win->renderer[0] != NULL)
//		SDL_DestroyRenderer(s_win->renderer[0]);
//	if (s_win->window[0] != NULL)
//		SDL_DestroyWindow(s_win->window[0]);
//	TTF_Quit();
	SDL_Quit();
	exit(status);
}

/*
** SDL_DestroyTexture(texture);
** SDL_FreeSurface(surface);
** TTF_CloseFont(font);
** SDL_DestroyRenderer(s_win->renderer);
*/

void		ft_quit_window(t_my_win *s_win, int index)
{
	if (s_win->renderer[index] != NULL)
		SDL_DestroyRenderer(s_win->renderer[0]);
	if (s_win->window[index] != NULL)
		SDL_DestroyWindow(s_win->window[0]);
	TTF_Quit();
}
