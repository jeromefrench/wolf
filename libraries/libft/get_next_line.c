/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:52:20 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/06 12:39:27 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int		ft_init(t_mystruct **mystruct)
{
	if (!((*mystruct) = (t_mystruct*)ft_memalloc(sizeof(t_mystruct))))
		return (-1);
	(*mystruct)->tmp = NULL;
	(*mystruct)->eof = 0;
	(*mystruct)->find = 0;
	(*mystruct)->ret_code = 1;
	return (1);
}

static int		ft_send_the_line(char **line, t_mystruct *mystruct)
{
	char	*str2;
	char	*swap;

	if (!(str2 = ft_strnew(ft_strchr(mystruct->tmp, '\n') - mystruct->tmp)))
		return (-1);
	*line = ft_strncpy(str2, mystruct->tmp, ft_strchr(mystruct->tmp, '\n') -
			mystruct->tmp);
	if (!(swap = ft_strdup(mystruct->tmp)))
		return (-1);
	free(mystruct->tmp);
	if (!(mystruct->tmp = ft_strdup(ft_strchr(swap, '\n') + 1)))
		return (mystruct->ret_code = -1);
	free(swap);
	mystruct->find = 1;
	mystruct->ret_code = 1;
	return (1);
}

static int		ft_end_of_file(char **line, t_mystruct *mystruct)
{
	if (ft_strchr(mystruct->tmp, '\n'))
	{
		if (!(ft_send_the_line(line, mystruct)))
			return (-1);
	}
	else
	{
		if (ft_strlen(mystruct->tmp) > 0)
		{
			mystruct->ret_code = 1;
			if (!(*line = ft_strdup(mystruct->tmp)))
				return (mystruct->ret_code = -1);
		}
		else
		{
			mystruct->ret_code = 0;
		}
		if (mystruct->tmp)
		{
			free(mystruct->tmp);
			mystruct->tmp = NULL;
		}
		mystruct->find = 1;
	}
	return (1);
}

static int		ft_in_the_file(t_mystruct *mystruct, const int fd, char **line)
{
	char	*tmp;

	if (mystruct->tmp && ft_strchr(mystruct->tmp, '\n') != NULL)
	{
		if (!(ft_send_the_line(line, mystruct)))
			return (mystruct->ret_code = 0);
	}
	else
	{
		if ((mystruct->size = read(fd, mystruct->str, BUFF_SIZE)) == -1)
			return (0);
		mystruct->str[mystruct->size] = '\0';
		mystruct->eof = (mystruct->size < BUFF_SIZE) ? 1 : 0;
		tmp = NULL;
		if (mystruct->tmp != NULL)
			if (!(tmp = ft_strdup(mystruct->tmp)))
				return (-1);
		free(mystruct->tmp);
		mystruct->tmp = !tmp ? ft_strdup(mystruct->str) :
			ft_strjoin(tmp, mystruct->str);
		if (mystruct->tmp == NULL)
			return (0);
		free(tmp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_mystruct	*mystruct = NULL;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if (fd < 0)
		return (-1);
	if (mystruct == NULL)
		if (!(ft_init(&mystruct)))
			return (-1);
	if (!(mystruct->str = ft_strnew(BUFF_SIZE + 1)))
		return (mystruct->ret_code = -1);
	while (!mystruct->find && !mystruct->eof)
		if (!(ft_in_the_file(mystruct, fd, line)))
			return (-1);
	if (mystruct->tmp == NULL)
		return (mystruct->ret_code = 0);
	if (!mystruct->find && mystruct->eof)
		if (!(ft_end_of_file(line, mystruct)))
			return (mystruct->ret_code = -1);
	free(mystruct->str);
	mystruct->find = 0;
	mystruct->str = NULL;
	mystruct->eof = 0;
	return (mystruct->ret_code);
}
