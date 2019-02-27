/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:34:27 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/01 10:54:12 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	length = ft_strlen(dst);
	while (dst[i] != '\0')
		i++;
	if (size > 0)
	{
		while (src[j] != '\0' && i < (int)(size - 1))
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (i >= (int)size)
		return (ft_strlen(src) + size);
	else
		return (length + ft_strlen(src));
}
