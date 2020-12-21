/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:44:18 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/14 17:19:08 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	if (!(dest = malloc(sizeof(*dest) * (len + 1))))
		return (0);
	while (s[i])
		i++;
	if (i < start)
	{
		*dest = '\0';
		return (dest);
	}
	i = 0;
	s = s + start;
	while (s[i] && len-- > 0)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
