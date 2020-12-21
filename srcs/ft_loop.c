/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:39:10 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 02:36:55 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_loop()
{
	int length;
	
	while(1)
	{
		length = recvfrom(g_mim.socket, g_mim.buffer, BUF_SIZE, 0, NULL, NULL);
		if (length == -1)
			return (ft_print_error("Something went wrong in recvfrom"));
		if (ntohs(g_mim.eh->h_proto) == ETH_P_ARP)
		{
			g_mim.ah = (t_arp_header *) g_mim.arphead;				
			if ( (htons(g_mim.ah->arp_op) == ARPOP_REQUEST) &&
				ft_compare_ip(g_mim.source_ip_tab, g_mim.ah->arp_spa) && 
				ft_compare_mac(g_mim.source_mac_tab, g_mim.ah->arp_sha) &&
				ft_compare_ip(g_mim.dest_ip_tab, g_mim.ah->arp_dpa)
				)
				{
					ft_recv();
					ft_send();
					return (0);
				}
		}
	}
	return (0);
}