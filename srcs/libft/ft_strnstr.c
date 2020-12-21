/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:27:20 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/14 18:20:21 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	char	*src;

	src = (char *)haystack;
	if (*needle == '\0')
		return (src);
	a = 0;
	while (a < len && src[a])
	{
		i = 0;
		while (src[a + i] == needle[i] && (a + i) < len)
		{
			if (needle[i + 1] == '\0')
				return (&src[a]);
			i++;
		}
		a++;
	}
	return (NULL);
}
