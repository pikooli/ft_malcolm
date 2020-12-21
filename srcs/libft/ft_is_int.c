/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:46:34 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/11 01:46:39 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_int(char *str)
{
	long ret;

	if (!ft_base_10(str))
		return (false);
	ret = ft_atoi(str);
	if (ret < -2147483648 || ret > 2147483647)
		return (false);
	return (true);
}
