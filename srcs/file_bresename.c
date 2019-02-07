/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bresename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:23:15 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/07 11:02:54 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf3d.h"

void			ft_put_the_line_third(t_my_win *s_win, t_myputtheline *s_line)
{
	s_line->ex = abs((int)s_line->un.a - (int)s_line->deux.a);
	s_line->ey = abs((int)s_line->un.b - (int)s_line->deux.b);
	s_line->dx = 2 * s_line->ex;
	s_line->dy = 2 * s_line->ey;
	s_line->d_x = s_line->ex;
	s_line->d_y = s_line->ey;
	s_line->i = 0;
	s_line->x_incr = 1;
	s_line->y_incr = 1;
	if (s_line->deux.a > s_line->un.a)
		s_line->x_incr = -1;
	if (s_line->deux.b > s_line->un.b)
		s_line->y_incr = -1;
	if (s_line->dy == 0)
		ft_case_one(s_win, s_line);
	if (s_line->d_x > s_line->d_y)
		ft_case_two(s_win, s_line);
	if (s_line->dx == s_line->dy)
		ft_case_three(s_win, s_line);
	if (s_line->d_x < s_line->d_y)
		ft_case_four(s_win, s_line);
	if (s_line->dx == 0)
		ft_case_five(s_win, s_line);
}
