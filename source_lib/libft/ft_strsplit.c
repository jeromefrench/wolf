/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:57:58 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/03 18:30:00 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static void	ft_split_first(char const *s, int *word, char *c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == *c && s[i] != '\0')
			i++;
		while (s[i] != *c && s[i] != '\0')
			i++;
		if (!(s[i] == '\0' && s[i - 1] == *c))
			*word = *word + 1;
	}
}

static void	ft_strtrim_second(const char *s, int *j, char *c, int *letter)
{
	while (s[*j] == *c && s[*j] != '\0')
		*j = *j + 1;
	*letter = 0;
	while (s[*j] != *c && s[*j] != '\0')
	{
		*letter = *letter + 1;
		*j = *j + 1;
	}
}

static int	ft_str_trim_third(int *word, const char *s, char *c, char **str)
{
	int		letter;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < *word)
	{
		ft_strtrim_second(s, &j, c, &letter);
		if (letter > 0)
		{
			if (!(str[i] = (char*)malloc(sizeof(char) * letter + 1)))
				return (0);
			j = j - letter;
			letter = 0;
			while (s[j] != *c && s[j] != '\0')
			{
				str[i][letter] = s[j];
				letter++;
				j++;
			}
			str[i][letter] = '\0';
		}
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		word;
	int		i;

	if (!s)
		return (NULL);
	word = 0;
	ft_split_first(s, &word, &c);
	if (!(str = (char**)malloc(sizeof(char*) * (word + 1))))
		return (0);
	if (word == 0)
	{
		str[0] = 0;
		return (str);
	}
	i = ft_str_trim_third(&word, s, &c, str);
	if (i == 0)
		return (0);
	else
		str[i] = 0;
	return (str);
}
