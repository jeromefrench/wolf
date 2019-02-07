/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:54:06 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/13 09:31:04 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	x;
	char	*str;
	int		i;

	i = 0;
	x = (char)c;
	str = (char*)s;
	while (str[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == x)
		{
			return (&str[i]);
		}
		i--;
	}
	return (NULL);
}
