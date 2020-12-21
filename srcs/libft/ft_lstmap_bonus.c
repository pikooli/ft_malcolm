/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:56 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/22 13:53:26 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnewone(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *begin;
	t_list *new;
	t_list *tmp;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	if (!(new = ft_lstnewone((*f)(lst->content))))
		return (0);
	lst = lst->next;
	begin = new;
	tmp = new;
	while (lst)
	{
		if (!(new = ft_lstnewone((*f)(lst->content))))
		{
			ft_lstclear(&begin, (*del));
			return (0);
		}
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (begin);
}
