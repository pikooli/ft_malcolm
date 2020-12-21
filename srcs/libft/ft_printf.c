/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:51:38 by paszhang          #+#    #+#             */
/*   Updated: 2020/12/20 21:51:34 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_atoi_special(char **str)
{
	int i;
	char*dest;
	int nbr;

	nbr = 0;
	dest = *str;
	i = 0;
	while (dest[i] >= '0' && dest[i] <= '9')
	{
		nbr *= 10;
		nbr += dest[i++] - '0';
	}
	*str = *str + i;
	return (nbr);
}

static int		ft_offset(int offset, int point, int i)
{
	int count;
	int moins;

	count = 0;
	moins = i < 0 ? 1 : 0;
	i = i < 0 ? -i : i;
	if (point != -1 && point > i)
		offset -= point - i;
	while (offset - count - moins > i)
	{
		write(1, " ", 1);
		count++;
	}
	if (moins)
		write(1, "-", 1);
	while (point-- > i)
	{
		write(1, "0", 1);
		count++;
	}
	return (count + moins);
}

static int		ft_conv(va_list ap, char c, int offset, int point)
{
	int				i;
	char			*str;
	long long		nd;
	unsigned int	nx;
	int				nbr;

	i = 0;
	nbr = 0;
	if (c == 's' && (str = va_arg(ap, char *)))
		i = ft_conv_s(str, point, offset);
	if (c == 'd')
	{
		nd = (long long)va_arg(ap, int);
		i = ft_conv_d(nd, 0);
		nbr = ft_offset(offset, point, i);
		i = i < 0 ? ft_conv_d(nd, -i) : ft_conv_d(nd, i);
	}
	if (c == 'x')
	{
		nx = (unsigned int)va_arg(ap, int);
		i = ft_conv_d(nx, 0);
		i += ft_offset(offset, point, i);
		ft_conv_x(nx, i);
	}
	return (i + nbr);
}

static int		ft_dete(va_list ap, char **str)
{
	int offset;
	int point;

	point = -1;
	offset = ft_atoi_special(str);
	if (**str == '.')
	{
		*str = *str + 1;
		point = ft_atoi_special(str);
	}
	return (ft_conv(ap, **str, offset, point));
}

int				ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += ft_dete(ap, &str);
			str++;
		}
		else
		{
			write(1, str++, 1);
			i++;
		}
	}
	va_end(ap);
	return (i);
}
