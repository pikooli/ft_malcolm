/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:47:53 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 01:48:22 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrendl(const char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}
