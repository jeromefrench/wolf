/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:32:58 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/20 11:37:52 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		n;
	int		i;
	size_t	p;
	size_t	len;

	n = 0;
	i = 0;
	p = 0;
	while (src[n] != '\0')
		n++;
	while (dst[p])
	{
		if (p >= size)
			return (size + n);
		p++;
	}
	if (p >= size)
		return (size + n);
	len = (unsigned int)(n + p);
	while (p < (size - 1) && src[i])
		dst[p++] = src[i++];
	dst[p] = '\0';
	return (len);
}
