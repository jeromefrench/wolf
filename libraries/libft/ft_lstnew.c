/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:09:16 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/04 08:10:25 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;

	if (!(new_node = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		new_node->content_size = 0;
		new_node->content = NULL;
	}
	else
	{
		new_node->content_size = content_size;
		if (!(new_node->content = (char*)malloc(sizeof(char) * content_size)))
			return (0);
		ft_memcpy(new_node->content, content, content_size);
	}
	new_node->next = NULL;
	return (new_node);
}
