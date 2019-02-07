/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:04:12 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/15 13:13:26 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (*alst && alst && *del)
	{
		tmp = *alst;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = tmp;
	}
	*alst = NULL;
}
