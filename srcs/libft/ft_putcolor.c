/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:46:14 by pascal            #+#    #+#             */
/*   Updated: 2020/12/20 19:14:03 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putcolor(char *color)
{
	if (!ft_strcmp("", color))
		ft_putstr("\033[0m");
	else if (!ft_strcmp("yellow", color))
		ft_putstr("\033[33m");
	else if (!ft_strcmp("magenta", color))
		ft_putstr("\033[35m");
	else if (!ft_strcmp("red", color))
		ft_putstr("\033[31m");
	else if (!ft_strcmp("blue", color))
		ft_putstr("\033[34m");
	else if (!ft_strcmp("green", color))
		ft_putstr("\033[32m");
}
