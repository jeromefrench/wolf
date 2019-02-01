/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:31:21 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/01 13:47:36 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	int				i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (ss1[i] != 0 && ss2[i] == ss1[i] && i < (n - 1))
		i++;
	return (ss1[i] - ss2[i]);
}
