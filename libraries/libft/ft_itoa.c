/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:07:49 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/15 12:59:02 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	tmp[11];
	char	*num;
	int		i;
	int		neg;
	int		j;

	i = 0;
	j = 0;
	neg = n < 0 ? -1 : 1;
	while (neg * n > 9 || neg * n < 0)
	{
		tmp[i++] = '0' + neg * (n % 10);
		n = n / 10;
	}
	tmp[i++] = '0' + neg * (n % 10);
	if (neg < 0)
		tmp[i++] = '-';
	if (!(num = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	num[i] = '\0';
	while (i--)
		num[i] = tmp[j++];
	return (num);
}
