/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:57:14 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/14 16:06:14 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (len-- > 0)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
