/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:33:36 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/20 12:21:36 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*src1;

	str = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	while (n > 0)
	{
		*str = *src1;
		str++;
		src1++;
		n--;
	}
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
	return ((unsigned char*)dst);
	return (NULL);
}
