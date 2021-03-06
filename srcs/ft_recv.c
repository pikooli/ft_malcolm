/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:39:31 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 03:26:39 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_recv(void)
{
	ft_printcolor("+++++++++ We receive a ARP REQUEST +++++++++", "blue");
	ft_print_ip("Sender ip", g_mim.ah->arp_spa);
	ft_print_mac("Sender Mac address", g_mim.ah->arp_sha);
	ft_print_ip("Dest ip", g_mim.ah->arp_dpa);
	ft_print_mac("Dest Mac address", g_mim.ah->arp_dha);
	ft_memcpy((void*)g_mim.etherhead,
			(const void*)(g_mim.etherhead + ETH_MAC_LEN),
				ETH_MAC_LEN);
	ft_memcpy((void*)(g_mim.etherhead + ETH_MAC_LEN),
			(const void*)g_mim.src_mac,
				ETH_MAC_LEN);
	ft_printcolor("+++++++++++++++++++++++++++++++++++++++", "magenta");
}
