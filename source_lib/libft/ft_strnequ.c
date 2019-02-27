/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 07:30:32 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/01 14:08:06 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (n == 0)
		return (1);
	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < ((int)n - 1))
	{
		if (s1[i] == s2[i])
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}
