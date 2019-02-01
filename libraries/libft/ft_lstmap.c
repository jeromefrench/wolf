/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchardin <jerome.chardin@outlook.co>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:21:17 by jchardin          #+#    #+#             */
/*   Updated: 2018/12/03 14:40:30 by jchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*new_lst_first_node;
	t_list	*tmp;

	new_lst_first_node = NULL;
	new_lst = NULL;
	new_lst = f(lst);
	new_lst_first_node = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = new_lst;
		new_lst = f(lst);
		tmp->next = new_lst;
		lst = lst->next;
	}
	return (new_lst_first_node);
}
