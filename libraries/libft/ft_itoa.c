/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:36:34 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/03 18:30:37 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_first(int *nega, int *n, int *nb, int *i)
{
	*nega = 1;
	if (*n < 0)
		*nega = -1;
	*n = *n * *nega;
	*i = 0;
	*nb = *n;
	while (*nb > 0)
	{
		*nb = *nb / 10;
		*i = *i + 1;
	}
}

static void	ft_itoa_third(int *nb, int *i, char *str, int *nega)
{
	str[*i] = '\0';
	*i = *i - 1;
	while (*nb > 0)
	{
		str[*i] = (*nb % 10) + '0';
		*nb = *nb / 10;
		*i = *i - 1;
	}
	if (*nega == -1)
		str[0] = '-';
}

static char	*ft_itoa_prime(int *n, char *str)
{
	if (*n == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	else
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
}

char		*ft_itoa(int n)
{
	int		i;
	int		nb;
	char	*str;
	int		nega;

	str = NULL;
	if (n == 0 || n == -2147483648)
		return (ft_itoa_prime(&n, str));
	ft_itoa_first(&nega, &n, &nb, &i);
	if (nega == -1)
	{
		if (!(str = malloc(sizeof(char) * i + 2)))
			return (0);
		i++;
	}
	else
	{
		if (!(str = malloc(sizeof(char) * i + 1)))
			return (0);
	}
	nb = n;
	ft_itoa_third(&nb, &i, str, &nega);
	return (str);
}
