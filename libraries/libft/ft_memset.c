/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:51:50 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/08 17:20:00 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = s;
	while (len--)
		*str++ = (unsigned char)c;
	return (s);
}
