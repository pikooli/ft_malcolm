/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 12:22:51 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/11 14:23:14 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_lenght(char const *s1, char const *s2)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (s1[i++])
		nbr++;
	i = 0;
	while (s2[i++])
		nbr++;
	return (nbr);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int i;
	char*dest;
	int b;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	b = ft_lenght(s1, s2);
	if (!(dest = malloc(sizeof(char) * (b + 1))))
		return (0);
	i = 0;
	b = 0;
	while (s1[b])
	{
		dest[i] = s1[b++];
		i++;
	}
	b = 0;
	while (s2[b])
	{
		dest[i] = s2[b++];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
