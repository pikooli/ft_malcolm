/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:21:36 by paszhang          #+#    #+#             */
/*   Updated: 2019/10/11 14:58:07 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *src;
	char *save;

	src = (char *)s;
	save = 0;
	while (*src)
	{
		if (*src == c)
			save = src;
		src++;
	}
	if (*src == c)
		save = src;
	return (save);
}
