/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randnumb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:55:36 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/16 21:55:38 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** don't forget to initial srand(time(NULL));
*/

int	ft_randnumb(int max)
{
	int nb;

	nb = rand();
	while (nb > max)
		nb %= max;
	return (nb);
}
