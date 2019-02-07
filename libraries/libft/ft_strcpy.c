/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:15:24 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/20 10:44:54 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*ptr;
	int		n;

	ptr = dest;
	n = 0;
	while (src[n] != '\0')
	{
		*ptr = src[n];
		n++;
		ptr++;
	}
	dest[n] = '\0';
	return (dest);
}
