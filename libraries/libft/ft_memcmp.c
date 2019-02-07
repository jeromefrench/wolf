/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:37:21 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/12 13:08:28 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *x;
	unsigned char *y;

	x = (unsigned char*)s1;
	y = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*x == *y && --n != 0)
	{
		x++;
		y++;
	}
	return (*x - *y);
}
