/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:30:24 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 03:01:27 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		checkbase(char *base)
{
	int a;
	int i;

	i = 0;
	while (base[i])
	{
		a = i + 1;
		while (base[a])
			if (base[i] == base[a++])
				return (0);
		if (base[i] < 32 || base[i] >= 127 || base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (1);
}

int		checkstr(char str, char *base)
{
	int index;

	index = -1;
	while (base[++index])
		if (str == base[index])
			return (index);
	return (-1);
}

int		conver(char *str, char *base, int nbase)
{
	int i;
	int nbr;
	int index;
	int power;

	power = 1;
	nbr = 0;
	i = 0;
	while (((index = checkstr(str[i], base)) != -1) && str[i] != '\0')
	{
		nbr += index * power;
		power *= nbase;
		i++;
	}
	return (nbr);
}

int		reverstr(char *str, char *base, int lenghttab, int nbase)
{
	int		i;
	int		a;
	int		nbr;
	char	tabstr[lenghttab];

	a = 0;
	i = lenghttab - 1;
	while (i >= 0)
	{
		tabstr[a] = str[i];
		a++;
		i--;
	}
	tabstr[a] = '\0';
	nbr = conver(tabstr, base, nbase);
	return (nbr);
}

int		ft_atoi_base(char *str, char *base)
{
	int i;
	int nbr;
	int moins;
	int a;

	if (!(checkbase(base)))
		return (0);
	a = 0;
	i = 0;
	nbr = 0;
	moins = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' ||
			str[i] == '\f' || str[i] == ' ' || str[i] == '\r')
		i++;
	while (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			moins *= -1;
	while (base[nbr])
		nbr++;
	while (checkstr(str[i + a], base) != -1 && str[i + a] != '\0')
		a++;
	nbr = reverstr(&str[i], base, a, nbr);
	return (nbr * moins);
}
