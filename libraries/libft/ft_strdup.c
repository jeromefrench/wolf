/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:53:26 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/20 10:51:58 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		n;
	int		p;
	char	*str;

	p = 0;
	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	if (!(str = (char*)malloc(sizeof(*src) * n + 1)))
		return (NULL);
	while (src[p] != '\0')
	{
		str[p] = src[p];
		p++;
	}
	str[p] = '\0';
	return (str);
}
