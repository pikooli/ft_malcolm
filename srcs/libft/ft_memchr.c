/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:25:12 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/11 14:38:26 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	cara;
	int				i;

	i = 0;
	src = (unsigned char *)s;
	cara = (unsigned char)c;
	while (n-- > 0)
		if (src[i] == cara)
			return (src + i);
		else
			i++;
	return (NULL);
}
