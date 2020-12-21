/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paszhang <paszhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:02:25 by paszhang          #+#    #+#             */
/*   Updated: 2020/05/16 23:05:07 by paszhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_conv_s(char *str, int point, int offset)
{
	int i;
	int	count;

	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i])
		i++;
	offset = point < i && point != -1 ? offset - point : offset - i;
	count = offset >= 0 ? offset : 0;
	while (offset-- > 0)
		write(1, " ", 1);
	i = 0;
	if (point == -1)
		while (str[i])
			write(1, &str[i++], 1);
	else
		while (str[i] && point--)
			write(1, &str[i++], 1);
	return (i + count);
}

int		ft_conv_x(unsigned int nbr, int mode)
{
	int i;
	char*c;

	c = "0123456789abcdef";
	i = 0;
	if (nbr > 15)
		i += ft_conv_x(nbr / 16, mode);
	if (mode)
		write(1, &c[nbr % 16], 1);
	return (i + 1);
}

int		ft_conv_d(long long nbr, int mode)
{
	int		i;
	char	c;
	int		moins;

	moins = nbr < 0 ? -1 : 1;
	nbr = nbr < 0 ? -nbr : nbr;
	i = 0;
	if (nbr > 9)
		i += ft_conv_d(nbr / 10, mode);
	c = nbr % 10 + '0';
	if (mode)
		write(1, &c, 1);
	return ((i + 1) * moins);
}
