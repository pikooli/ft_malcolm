/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 23:38:58 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 02:23:55 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void ft_placing_fake_addr()
{
	mim.ah->arp_sha[0] = mim.dest_mac_tab[0];
    mim.ah->arp_sha[1] = mim.dest_mac_tab[1];
    mim.ah->arp_sha[2] = mim.dest_mac_tab[2];
    mim.ah->arp_sha[3] = mim.dest_mac_tab[3];
    mim.ah->arp_sha[4] = mim.dest_mac_tab[4];
    mim.ah->arp_sha[5] = mim.dest_mac_tab[5];
	ft_print_mac("Going to send this mac address : ", mim.dest_mac_tab);
}

void ft_swap_address()
{
	unsigned char buf_arp_dpa[4];
	
	buf_arp_dpa[0] = mim.ah->arp_dpa[0];
    buf_arp_dpa[1] = mim.ah->arp_dpa[1];
    buf_arp_dpa[2] = mim.ah->arp_dpa[2];
    buf_arp_dpa[3] = mim.ah->arp_dpa[3];
	
    mim.ah->arp_dha[0] = mim.ah->arp_sha[0];
    mim.ah->arp_dha[1] = mim.ah->arp_sha[1];
    mim.ah->arp_dha[2] = mim.ah->arp_sha[2];
    mim.ah->arp_dha[3] = mim.ah->arp_sha[3];
    mim.ah->arp_dha[4] = mim.ah->arp_sha[4];
    mim.ah->arp_dha[5] = mim.ah->arp_sha[5];

    mim.ah->arp_dpa[0] = mim.ah->arp_spa[0];
    mim.ah->arp_dpa[1] = mim.ah->arp_spa[1];
    mim.ah->arp_dpa[2] = mim.ah->arp_spa[2];
    mim.ah->arp_dpa[3] = mim.ah->arp_spa[3];

    mim.ah->arp_spa[0] = buf_arp_dpa[0];
    mim.ah->arp_spa[1] = buf_arp_dpa[1];
    mim.ah->arp_spa[2] = buf_arp_dpa[2];
    mim.ah->arp_spa[3] = buf_arp_dpa[3];
}

int ft_send()
{
	int sent;
	
    ft_printcolor("\n&&&&&&&&&&&&&&&&&&&&&&&& SEND RESPONSE &&&&&&&&&&&&&&&&&&&&&&&&&&&&\n", "red");
	mim.ah->arp_op = htons(ARPOP_REPLY); 
  	ft_swap_address();
	mim.socket_addr.sll_addr[0] = mim.eh->h_dest[0];
    mim.socket_addr.sll_addr[1] = mim.eh->h_dest[1];
    mim.socket_addr.sll_addr[2] = mim.eh->h_dest[2];
    mim.socket_addr.sll_addr[3] = mim.eh->h_dest[3];
    mim.socket_addr.sll_addr[4] = mim.eh->h_dest[4];
    mim.socket_addr.sll_addr[5] = mim.eh->h_dest[5];
	ft_placing_fake_addr();
	ft_print_ip("sender ip : ", mim.ah->arp_spa);
	ft_print_mac("sender mac address : ", mim.ah->arp_sha);
	ft_print_ip("dest ip : ", mim.ah->arp_dpa);
	ft_print_mac("dest mac address : ", mim.ah->arp_dha);
	sent = sendto(mim.socket, mim.buffer, BUF_SIZE, 0, 
        (struct sockaddr *) &mim.socket_addr, sizeof(mim.socket_addr));
	ft_printcolor("\n **************** RESPONSE IS SEND ****************\n", "red");
    if (sent == -1)
    {
        perror("sendto():");
        return (1);
    }
	return (0);
}