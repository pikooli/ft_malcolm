/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:29:18 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 03:24:58 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_print(char *str)
{
	ft_putcolor("green");
	printf("%s\n", str);
	ft_putcolor("");
}

void	ft_printcolor(char *str, char *color)
{
	ft_putcolor(color);
	printf("%s\n", str);
	ft_putcolor("");
}

void	ft_print_mac(char *str, unsigned char src[6])
{
	ft_putcolor("green");
	printf("%s : %02X:%02X:%02X:%02X:%02X:%02X\n",
		str,
		src[0],
		src[1],
		src[2],
		src[3],
		src[4],
		src[5]);
	ft_putcolor("");
}

void	ft_print_ip(char *str, unsigned char src[4])
{
	ft_putcolor("green");
	printf("%s : %02d:%02d:%02d:%02d\n",
		str,
		src[0],
		src[1],
		src[2],
		src[3]);
	ft_putcolor("");
}
