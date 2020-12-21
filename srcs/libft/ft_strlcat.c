/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:22:48 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/10 12:35:29 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int				a;
	unsigned int	i;
	unsigned int	lenght;

	i = 0;
	a = 0;
	lenght = 0;
	while (dst[i] != '\0')
		i++;
	while (src[lenght])
		lenght++;
	if (dstsize <= i)
		return (lenght + dstsize);
	lenght += i;
	while (i < (dstsize - 1) && src[a] != '\0')
	{
		dst[i] = src[a++];
		i++;
	}
	dst[i] = '\0';
	return (lenght);
}
