/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 11:38:15 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/01 12:22:02 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		cmp;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		cmp = (int)s[i];
		if (cmp == c)
			return ((void*)(s + i));
		i--;
	}
	return (NULL);
}
