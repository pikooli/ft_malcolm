/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shuffle_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 00:16:56 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/17 00:17:54 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_shuffle_array(int *array, int size)
{
	int i;
	int tmp;
	int j;

	i = -1;
	if (size < 1)
		return ;
	while (++i < size)
	{
		j = i + ft_randnumb(size - i);
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
	}
}
