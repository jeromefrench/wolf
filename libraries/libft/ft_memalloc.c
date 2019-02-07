/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:31:06 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/16 16:35:47 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (0);
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
