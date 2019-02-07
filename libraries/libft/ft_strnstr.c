/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:16:07 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/15 19:15:29 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t		n;
	int			p;
	char		*ptr;

	n = 0;
	ptr = (char*)hay;
	if (*need == '\0')
		return ((char*)hay);
	while (hay[n] && n < len)
	{
		if (hay[n] == need[0])
		{
			p = 0;
			while (need[p] == hay[n + p] && hay[n + p] != '\0')
			{
				p++;
				if (need[p] == '\0' && (p + n) <= len)
					return (&ptr[n]);
			}
		}
		n++;
	}
	return (NULL);
}
