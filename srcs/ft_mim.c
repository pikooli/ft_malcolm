/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:11:28 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 00:44:30 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_get_device_info()
{
	int i;

	ft_print("Getting device information");
	ft_strcpy(mim.ifr.ifr_name, DEVICE);
	printf("device %s\n",mim.ifr.ifr_name);
	if (ioctl(mim.socket, SIOCGIFINDEX, &mim.ifr) == -1)
		return (ft_print_error("Error in SIOCGIFINDEX "));
	mim.ifindex = mim.ifr.ifr_ifindex;
	if (ioctl(mim.socket, SIOCGIFHWADDR, &mim.ifr) == -1)
		return (ft_print_error("Error in SIOCGIFHWADDR "));
	i = -1;
	while(++i < 6)
		mim.src_mac[i] = mim.ifr.ifr_hwaddr.sa_data[i];
	ft_getIpAddress();
	ft_print_mac("Your MAC address is", mim.src_mac);
	return (0);
}

void ft_prepare_socketaddr()
{
	mim.socket_addr.sll_family = PF_PACKET; 
    mim.socket_addr.sll_protocol = htons(ETH_P_ARP); 
    mim.socket_addr.sll_ifindex = mim.ifindex; 
    mim.socket_addr.sll_hatype = ARPHRD_ETHER;
    mim.socket_addr.sll_pkttype = 0; 
    mim.socket_addr.sll_halen = 0;
    mim.socket_addr.sll_addr[6] = 0x00;
    mim.socket_addr.sll_addr[7] = 0x00;
	ft_print("------------- Connection create waiting for package -------------");
}

int ft_mim()
{
	ft_print("------------- Min going to proceed -------------");
	mim.socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (mim.socket == -1)
		return (ft_print_error("socket didn't create"));
	ft_printf("Socket create at : %d\n", mim.socket);
	if(ft_get_device_info())
		return (ft_print_error("Error in getting device"));
	ft_prepare_socketaddr();
	ft_loop();
	close(mim.socket);
	return (0);
}