/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getIpAddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:11:40 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 03:20:00 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_getipaddress(void)
{
	struct ifaddrs		*ifap;
	struct ifaddrs		*ifa;
	struct sockaddr_in	*sa;
	char				*addr;

	getifaddrs(&ifap);
	ifa = ifap;
	while (ifa)
	{
		if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET)
		{
			sa = (struct sockaddr_in *)ifa->ifa_addr;
			addr = inet_ntoa(sa->sin_addr);
			if (ft_strcmp(ifa->ifa_name, "lo"))
			{
				ft_putcolor("yellow");
				printf("Your ip address is: %s\n", ifa->ifa_name);
				printf("Your ip address is: %s\n", addr);
				ft_putcolor("");
			}
		}
		ifa = ifa->ifa_next;
	}
	if (ifap)
		freeifaddrs(ifap);
}
