/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:45:22 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 01:46:09 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free_split(char ***split)
{
	char **current;

	if (split && *split)
	{
		current = *split;
		while (current)
			free(*(current++));
		free(*split);
		*split = NULL;
	}
	return (NULL);
}
