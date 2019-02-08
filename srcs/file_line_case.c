/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_line_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:52:12 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/08 16:23:35 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_case_one(t_my_win *s_win, t_myputtheline *s_line)
{
	s_win->index = 0;
	while (s_line->i <= s_line->d_x)
	{
		(s_line->i)++;
		SDL_RenderDrawPoint(s_win->renderer[s_win->index], (int)s_line->deux.a, (int)s_line->deux.b);
		s_line->deux.a += s_line->x_incr;
	}
}

void			ft_case_two(t_my_win *s_win, t_myputtheline *s_line)
{
	s_win->index = 0;
	while (s_line->i <= s_line->d_x)
	{
		SDL_RenderDrawPoint(s_win->renderer[s_win->index], (int)s_line->deux.a, (int)s_line->deux.b);
		(s_line->i)++;
		s_line->deux.a += s_line->x_incr;
		s_line->ex -= s_line->dy;
		if (s_line->ex < 0)
		{
			s_line->deux.b += s_line->y_incr;
			s_line->ex += s_line->dx;
		}
	}
}

void			ft_case_three(t_my_win *s_win, t_myputtheline *s_line)
{
	s_win->index = 0;
	while (s_line->i <= s_line->d_x)
	{
		(s_line->i)++;
		SDL_RenderDrawPoint(s_win->renderer[s_win->index], (int)s_line->deux.a, (int)s_line->deux.b);
		s_line->deux.a += s_line->x_incr;
		s_line->deux.b += s_line->y_incr;
	}
}

void			ft_case_four(t_my_win *s_win, t_myputtheline *s_line)
{
	s_win->index = 0;
	while (s_line->i <= s_line->d_y)
	{
		SDL_RenderDrawPoint(s_win->renderer[s_win->index], (int)s_line->deux.a, (int)s_line->deux.b);
		(s_line->i)++;
		s_line->deux.b += s_line->y_incr;
		s_line->ey -= s_line->dx;
		if (s_line->ey < 0)
		{
			s_line->deux.a += s_line->x_incr;
			s_line->ey += s_line->dy;
		}
	}
}

void			ft_case_five(t_my_win *s_win, t_myputtheline *s_line)
{
	s_win->index = 0;
	while (s_line->i <= s_line->d_y)
	{
		(s_line->i)++;
		SDL_RenderDrawPoint(s_win->renderer[s_win->index], (int)s_line->deux.a, (int)s_line->deux.b);
		s_line->deux.b += s_line->y_incr;
	}
}
