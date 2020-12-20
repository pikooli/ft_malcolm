/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 17:32:53 by pascal            #+#    #+#             */
/*   Updated: 2020/12/20 19:43:55 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_check_hexa(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_ishexa(str[i++]))
			return (0);
	}
	return (i == 2 ? 1 : 0);
}

int	ft_check_ip(char *ip)
{
	char	**tab;
	int		i;
	int		num;

	i = 0;
	if (ip == NULL || (tab = ft_split(ip, '.')) == NULL)
		return (0);
	while (tab[i])
	{
		if (!ft_valid_number(tab[i]))
			return (!ft_free_tab(tab));
		num = ft_atoi(tab[i++]);
		if (0 < num && num > 255)
			return (!ft_free_tab(tab));
	}
	if (i != 4)
		return (!ft_free_tab(tab));
	return (ft_free_tab(tab));
}

int	ft_check_mac(char *mac)
{
	char	**tab;
	int		i;
	int		num;

	i = 0;
	if (mac == NULL || (tab = ft_split(mac, ':')) == NULL)
		return (0);
	while (tab[i])
	{
		if (!ft_check_hexa(tab[i++]))
			return (!ft_free_tab(tab));
	}
	if (i != 6)
		return (!ft_free_tab(tab));
	return (ft_free_tab(tab));
}

int	ft_check_arg(int ac, char **av)
{
	if (ac != 5)
	{
		ft_print_error("No valid number of argument, argument should be :");
		return (ft_print_error(\
		"source ip, source mac address, dest ip, dest mac address\n"));
	}
	if (!ft_check_ip(av[1]))
		return (ft_print_error("it source ip is not valid"));
	if (!ft_check_mac(av[2]))
		return (ft_print_error("it source mac address is not valid"));
	if (!ft_check_ip(av[3]))
		return (ft_print_error("it dest ip is not valid"));
	if (!ft_check_mac(av[4]))
		return (ft_print_error("it dest mac address is not valid"));
	return (0);
}
