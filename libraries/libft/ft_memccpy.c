/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:09:03 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/15 12:51:04 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*src1;
	unsigned char	x;
	size_t			i;

	str = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		str[i] = src1[i];
		if (src1[i] == x)
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}
