/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:16:01 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/14 16:18:49 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *src;

	src = (char *)s;
	while (*src)
		if (*src == c)
			return (src);
		else
			src++;
	if (*src == c)
		return (src);
	return (NULL);
}
