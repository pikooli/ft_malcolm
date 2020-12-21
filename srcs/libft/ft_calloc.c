/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:05:16 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/14 15:10:44 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *p;
	char *save;

	if (!(p = malloc(count * size)))
		return (0);
	save = (char *)p;
	count = size * count;
	while (count-- > 0)
	{
		*save = '\0';
		save++;
	}
	return (p);
}
