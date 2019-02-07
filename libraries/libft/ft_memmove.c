/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:25:32 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/12 18:46:14 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*src1;

	str = (unsigned char*)dst;
	src1 = (unsigned char*)src;
	if (str > src1)
	{
		str += len - 1;
		src1 += len - 1;
		while (len > 0)
		{
			*str-- = *src1--;
			len--;
		}
	}
	else
		ft_memcpy(str, src1, len);
	return ((unsigned char*)dst);
}
