/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:56:54 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/04 08:30:42 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_strtrimthird(int *i, char *swap, char *swap2)
{
	int		j;

	j = 0;
	while (swap[*i] != '\0')
	{
		swap2[j] = swap[*i];
		j = j + 1;
		*i = *i + 1;
	}
	swap2[j] = '\0';
	*i = 0;
	while (swap2[*i] != '\0')
		*i = *i + 1;
}

static void		ft_strtrimsecond(int *i, const char *s, char *swap, char *swap2)
{
	*i = 0;
	while (s[*i] != '\0')
	{
		swap[*i] = s[*i];
		*i = *i + 1;
	}
	swap[*i] = '\0';
	*i = *i - 1;
	while (swap[*i] == ' ' || swap[*i] == '\n' || swap[*i] == '\t')
	{
		swap[*i] = '\0';
		*i = *i - 1;
	}
	*i = 0;
	while (swap[*i] == ' ' || swap[*i] == '\n' || swap[*i] == '\t')
		*i = *i + 1;
	ft_strtrimthird(i, swap, swap2);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	char	*swap;
	char	*swap2;
	char	*str;

	if (s == 0)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(swap = malloc(sizeof(char) * (i + 1))))
		return (0);
	if (!(swap2 = malloc(sizeof(char) * (i + 1))))
		return (0);
	ft_strtrimsecond(&i, s, swap, swap2);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = -1;
	while (swap2[++i] != '\0')
		str[i] = swap2[i];
	str[i] = '\0';
	free(swap);
	free(swap2);
	return (str);
}
