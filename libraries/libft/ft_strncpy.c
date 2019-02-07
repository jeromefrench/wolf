/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:19:02 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/20 10:46:09 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	char	*str;

	str = dest;
	while (n > 0 && *src != '\0')
	{
		*str = *src;
		src++;
		str++;
		n--;
	}
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
	return (dest);
}
