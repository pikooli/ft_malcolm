/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:16:40 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/14 17:22:03 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*source;
	size_t				i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dst < src)
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	else
		while (i < len)
		{
			dest[len - i - 1] = source[len - i - 1];
			i++;
		}
	return (dst);
}
