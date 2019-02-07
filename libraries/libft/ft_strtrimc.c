/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:59:09 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/14 18:33:22 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	if (s)
	{
		while (s[i] && s[i] == c)
		{
			i++;
			if (s[i + 1] == '\0')
				return (ft_strdup(""));
		}
		len = ft_strlen((char*)s) - 1;
		while (s[len] == c && s[len] != s[i])
			len--;
		len++;
		if (len == i)
			return (ft_strdup(""));
		str = ft_strsub(s, i, (len - i));
		return (str);
	}
	return (NULL);
}
