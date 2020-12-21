/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:38:58 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 11:29:47 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_placing_fake_addr(void)
{
	g_mim.ah->arp_sha[0] = g_mim.dest_mac_tab[0];
	g_mim.ah->arp_sha[1] = g_mim.dest_mac_tab[1];
	g_mim.ah->arp_sha[2] = g_mim.dest_mac_tab[2];
	g_mim.ah->arp_sha[3] = g_mim.dest_mac_tab[3];
	g_mim.ah->arp_sha[4] = g_mim.dest_mac_tab[4];
	g_mim.ah->arp_sha[5] = g_mim.dest_mac_tab[5];
	ft_print_mac("Going to send this mac address : ", g_mim.dest_mac_tab);
}

void	ft_swap_address(void)
{
	unsigned char buf_arp_dpa[4];

	buf_arp_dpa[0] = g_mim.ah->arp_dpa[0];
	buf_arp_dpa[1] = g_mim.ah->arp_dpa[1];
	buf_arp_dpa[2] = g_mim.ah->arp_dpa[2];
	buf_arp_dpa[3] = g_mim.ah->arp_dpa[3];
	g_mim.ah->arp_dha[0] = g_mim.ah->arp_sha[0];
	g_mim.ah->arp_dha[1] = g_mim.ah->arp_sha[1];
	g_mim.ah->arp_dha[2] = g_mim.ah->arp_sha[2];
	g_mim.ah->arp_dha[3] = g_mim.ah->arp_sha[3];
	g_mim.ah->arp_dha[4] = g_mim.ah->arp_sha[4];
	g_mim.ah->arp_dha[5] = g_mim.ah->arp_sha[5];
	g_mim.ah->arp_dpa[0] = g_mim.ah->arp_spa[0];
	g_mim.ah->arp_dpa[1] = g_mim.ah->arp_spa[1];
	g_mim.ah->arp_dpa[2] = g_mim.ah->arp_spa[2];
	g_mim.ah->arp_dpa[3] = g_mim.ah->arp_spa[3];
	g_mim.ah->arp_spa[0] = buf_arp_dpa[0];
	g_mim.ah->arp_spa[1] = buf_arp_dpa[1];
	g_mim.ah->arp_spa[2] = buf_arp_dpa[2];
	g_mim.ah->arp_spa[3] = buf_arp_dpa[3];
}

int		ft_send(void)
{
	int sent;

	ft_printcolor("\n&&&&&&&&&&&&&& SEND RESPONSE &&&&&&&&&&&&&&\n", "red");
	g_mim.ah->arp_op = htons(ARPOP_REPLY);
	ft_swap_address();
	g_mim.socket_addr.sll_addr[0] = g_mim.eh->h_dest[0];
	g_mim.socket_addr.sll_addr[1] = g_mim.eh->h_dest[1];
	g_mim.socket_addr.sll_addr[2] = g_mim.eh->h_dest[2];
	g_mim.socket_addr.sll_addr[3] = g_mim.eh->h_dest[3];
	g_mim.socket_addr.sll_addr[4] = g_mim.eh->h_dest[4];
	g_mim.socket_addr.sll_addr[5] = g_mim.eh->h_dest[5];
	ft_placing_fake_addr();
	ft_print_ip("sender ip : ", g_mim.ah->arp_spa);
	ft_print_mac("sender mac address : ", g_mim.ah->arp_sha);
	ft_print_ip("dest ip : ", g_mim.ah->arp_dpa);
	ft_print_mac("dest mac address : ", g_mim.ah->arp_dha);
	sent = sendto(g_mim.socket, g_mim.buffer, BUF_SIZE, 0,
	(struct sockaddr *)&g_mim.socket_addr, sizeof(g_mim.socket_addr));
	ft_printcolor("\n************* RESPONSE IS SEND *************\n", "red");
	free(g_mim.buffer);
	if (sent == -1)
		return (ft_print_error("Error in sendto"));
	return (0);
}
