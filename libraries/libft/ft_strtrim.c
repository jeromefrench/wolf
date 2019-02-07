/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:57:02 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/14 14:42:43 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = 0;
	if (s)
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		{
			i++;
			if (s[i + 1] == '\0')
				return (ft_strdup(""));
		}
		len = ft_strlen((char*)s) - 1;
		while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') &&
			s[len] != s[i])
			len--;
		len++;
		if (len == i)
			return (ft_strdup(""));
		str = ft_strsub(s, i, (len - i));
		return (str);
	}
	return (NULL);
}
