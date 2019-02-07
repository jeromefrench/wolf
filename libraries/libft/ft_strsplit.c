/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:21:04 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/16 11:04:14 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen1(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strsub1(char const *s, unsigned int start, size_t len)
{
	char			*r;
	unsigned int	i;

	i = 0;
	if (!s || !(r = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}

static int	ft_isnot(int c, char x)
{
	if (c != x)
		return (1);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	size;
	unsigned int	start;
	int				i;

	if (!s || !(tab = (char **)malloc(sizeof(char *) *
		(ft_strlen1((char*)s) + 1))))
		return (NULL);
	i = 0;
	size = 0;
	while (s[i])
	{
		if (ft_isnot(s[i], c))
		{
			start = i;
			while (s[i] && ft_isnot(s[i], c))
				i++;
			tab[size++] = ft_strsub1(s, start, i - start);
		}
		else
			i++;
	}
	tab[size] = NULL;
	return (tab);
}
