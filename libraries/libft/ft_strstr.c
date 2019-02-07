/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:43:07 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/12 18:20:38 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			n;
	int			p;
	const char	*ptr;

	n = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[n] != 0)
	{
		p = 0;
		while (needle[p] == haystack[n + p])
		{
			if (needle[p + 1] == '\0')
			{
				ptr = haystack + n;
				return ((char*)ptr);
			}
			p++;
		}
		n++;
	}
	return (NULL);
}
