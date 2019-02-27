/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 12:02:21 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/01 10:46:53 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < (int)len)
	{
		while (haystack[i + j] == needle[j] && (i + j) < (int)len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
