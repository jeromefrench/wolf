/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:31:00 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/15 17:37:36 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	x;
	unsigned long	i;

	i = 0;
	str = (unsigned char*)s;
	x = (unsigned char)c;
	while (n > i)
	{
		if (str[i] == x)
			return (str + i);
		i++;
	}
	return (NULL);
}
