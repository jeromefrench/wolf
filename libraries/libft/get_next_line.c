/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:16:14 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/09 11:44:24 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_newl(char **stock, int fd, int ret, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (stock[fd][i] != '\n' && stock[fd][i] != '\0')
	{
		i++;
	}
	if (stock[fd][i] == '\n')
	{
		*line = ft_strsub(stock[fd], 0, i);
		tmp = ft_strdup(stock[fd] + i + 1);
		free(stock[fd]);
		stock[fd] = tmp;
		if (stock[fd][0] == '\0')
			ft_strdel(&stock[fd]);
	}
	else if (stock[fd][i] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(stock[fd]);
		ft_strdel(&stock[fd]);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock[255];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (stock[fd] == NULL)
			stock[fd] = ft_strnew(1);
		tmp = ft_strjoin(stock[fd], buff);
		free(stock[fd]);
		stock[fd] = tmp;
		if (ft_strrchr(buff, '\n'))
		{
			break ;
		}
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (stock[fd] == NULL || stock[fd] == '\0'))
		return (0);
	return (ft_newl(stock, fd, ret, line));
}
