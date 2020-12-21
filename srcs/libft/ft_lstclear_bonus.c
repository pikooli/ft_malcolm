/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:45:29 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/11 12:39:35 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;
	t_list *current;

	if (lst == NULL || (*del) == NULL)
		return ;
	current = *lst;
	*lst = NULL;
	while (current)
	{
		(*del)(current->content);
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
