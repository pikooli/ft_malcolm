/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:39:10 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 01:34:54 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_loop()
{
	int length;
	
	while(1)
	{
		length = recvfrom(mim.socket, mim.buffer, BUF_SIZE, 0, NULL, NULL);
		if (length == -1)
			return (ft_print_error("Something went wrong in recvfrom"));
		if (ntohs(mim.eh->h_proto) == ETH_P_ARP)
		{
			mim.ah = (t_arp_header *) mim.arphead;				
			if ( (htons(mim.ah->arp_op) == ARPOP_REQUEST) &&
				ft_compare_ip(mim.source_ip_tab, mim.ah->arp_spa) && 
				ft_compare_mac(mim.source_mac_tab, mim.ah->arp_sha) &&
				ft_compare_ip(mim.dest_ip_tab, mim.ah->arp_dpa)
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