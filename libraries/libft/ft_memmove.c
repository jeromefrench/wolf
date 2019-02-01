/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:16:24 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/01 10:54:52 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	i = 0;
	if (dst < src)
	{
		while (i < (int)len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	else
	{
		i = len - 1;
		while (i > -1)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i--;
		}
	}
	return (dst);
}
