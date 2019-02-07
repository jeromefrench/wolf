/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:26:33 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/15 15:12:52 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;
	int		length;

	if (s && f)
	{
		i = 0;
		length = ft_strlen((char*)s);
		if (!(dest = (char*)malloc(sizeof(char) * length + 1)))
			return (0);
		while (i < length)
		{
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return ((char*)dest);
	}
	return (NULL);
}
