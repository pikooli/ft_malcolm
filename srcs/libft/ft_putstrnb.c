/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:16:47 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/17 00:16:48 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrnb(const char *str, int nb)
{
	ft_putstr(str);
	ft_putstr(" : ");
	ft_putnbr(nb);
	ft_putstr("\n");
}
