/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:25:04 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/14 15:57:02 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *source;
	unsigned char *dest;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n-- > 0)
	{
		*dest = *source;
		dest++;
		if (*source == (unsigned char)c)
			return ((void*)dest);
		source++;
	}
	return (NULL);
}
