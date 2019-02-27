/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:42:26 by jchardin          #+#    #+#             */
/*   Updated: 2019/02/27 17:17:59 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 32

int					get_next_line(const int fd, char **line);
typedef struct		s_mystruct
{
	char			*tmp;
	int				eof;
	int				find;
	int				size;
	int				ret_code;
	char			*str;
}					t_mystruct;

#endif
