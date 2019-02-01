/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:29:07 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/01 10:49:22 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	int		i;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < (int)(size + 1))
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
