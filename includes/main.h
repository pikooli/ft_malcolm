/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:00:00 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 01:05:27 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libft.h"
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <asm/types.h>
#include <ifaddrs.h>

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>




#define BUF_SIZE 42
#define DEVICE "enp0s3" // name of the ethernet cart
#define ETH_P_NULL 0x0 
#define ETH_MAC_LEN ETH_ALEN // octer in one ethernet addr
#define ETH_ARP 0x0806  // etherType for ARP protocol 

typedef struct __attribute__((packed)) s_arp_header /* __attribute allows to tell the compiler 
how you want to manage the memory for this struct*/
{
    // this structure is for arp header 
    unsigned short arp_hd; // arp hardware type (HTYPE) 
    unsigned short arp_pr; // arp protocol type (PTYPE)
    unsigned char arp_hdl; // arp hardware length (HLEN)
    unsigned char arp_prl; // arp protocol length (PLEN)
    unsigned short arp_op; // arp operation request (request 1 reply 2)
    unsigned char arp_sha[6]; // sender hardware address (SHA) MAC
    unsigned char arp_spa[4]; // sender protocol address (SPA) ip
    unsigned char arp_dha[6]; // target hardware address (THA) MAC
    unsigned char arp_dpa[4]; // target protocol address (TPA) ip
    // 224 bits 
}									t_arp_header;

typedef struct __attribute__((packed)) s_mim 
{
	char *source_ip;
    unsigned char source_ip_tab[4];
	char *source_mac;
    unsigned char source_mac_tab[6];
	char *dest_ip;
    unsigned char dest_ip_tab[4];
	char *dest_mac;
    unsigned char dest_mac_tab[6];
	int socket;
    unsigned char *buffer;
    unsigned char *etherhead;
    struct ethhdr *eh;
    struct sockaddr_ll socket_addr;
    unsigned char *arphead;
    struct ifreq ifr;
	int ifindex;
    unsigned char src_mac[6];
	t_arp_header *ah;

}               t_mim;

t_mim mim;

void		ft_getIpAddress();
int			ft_print_error(char *str);
int			ft_check_arg(int ac, char **av);
void		ft_sigint();
void		ft_print(char *str);
int			ft_mim();
void	ft_print_mac(char *str, unsigned char src[6]);
void	ft_print_ip(char *str, unsigned char src[4]);
void	ft_printcolor(char *str, char *color);
// loop 
int ft_loop();
void ft_recv();
int ft_send();

// compare
int ft_compare_mac(unsigned char *mac1, unsigned char *mac2);
int ft_compare_ip(unsigned char *ip1, unsigned char *ip2);

int test();
#endif
