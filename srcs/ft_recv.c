/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:39:31 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 01:25:53 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void ft_recv()
{
	ft_printcolor("+++++++++ We receive a ARP REQUEST +++++++++", "blue");
	ft_print_ip("Sender ip", mim.ah->arp_spa);
	ft_print_mac("Sender Mac address", mim.ah->arp_sha);
	ft_print_ip("Dest ip", mim.ah->arp_dpa);
	ft_print_mac("Dest Mac address", mim.ah->arp_dha);
	memcpy( (void*)mim.etherhead, (const void*)(mim.etherhead + ETH_MAC_LEN),
                ETH_MAC_LEN);
	memcpy( (void*)(mim.etherhead + ETH_MAC_LEN), (const void*)mim.src_mac,
                ETH_MAC_LEN);
	ft_printcolor("+++++++++++++++++++++++++++++++++++++++", "magenta");

}