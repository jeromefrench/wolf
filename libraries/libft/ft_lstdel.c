/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:13:42 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/15 13:35:59 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*tmp1;

	if (!*alst || !alst || !*del)
		return ;
	tmp1 = *alst;
	while (tmp1)
	{
		tmp = tmp1;
		tmp1 = tmp1->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
	*alst = NULL;
}
