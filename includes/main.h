/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:00:00 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 03:38:08 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "libft.h"
# include <sys/socket.h>
# include <sys/ioctl.h>
# include <sys/time.h>
# include <asm/types.h>
# include <ifaddrs.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <arpa/inet.h>
# include <linux/if_packet.h>
# include <linux/if_ether.h>
# include <linux/if_arp.h>
# include <signal.h>
# define BUF_SIZE 42
# define DEVICE "enp0s3"
# define ETH_P_NULL 0x0
# define ETH_MAC_LEN ETH_ALEN
# define ETH_ARP 0x0806

typedef	struct		s_arp_header
{
	unsigned short	arp_hd;
	unsigned short	arp_pr;
	unsigned char	arp_hdl;
	unsigned char	arp_prl;
	unsigned short	arp_op;
	unsigned char	arp_sha[6];
	unsigned char	arp_spa[4];
	unsigned char	arp_dha[6];
	unsigned char	arp_dpa[4];
}					t_arp_header;

typedef struct		s_mim
{
	int					socket;
	int					ifindex;
	char				*source_ip;
	unsigned char		source_ip_tab[4];
	char				*source_mac;
	unsigned char		source_mac_tab[6];
	char				*dest_ip;
	unsigned char		dest_ip_tab[4];
	char				*dest_mac;
	unsigned char		dest_mac_tab[6];
	unsigned char		*buffer;
	unsigned char		*etherhead;
	struct ethhdr		*eh;
	struct sockaddr_ll	socket_addr;
	unsigned char		*arphead;
	struct ifreq		ifr;
	unsigned char		src_mac[6];
	t_arp_header		*ah;
}					t_mim;

t_mim g_mim;

void				ft_getipaddress(void);
int					ft_print_error(char *str);
int					ft_check_arg(int ac, char **av);
void				ft_sigint(int i);
void				ft_print(char *str);
int					ft_mim(void);
void				ft_print_mac(char *str, unsigned char src[6]);
void				ft_print_ip(char *str, unsigned char src[4]);
void				ft_printcolor(char *str, char *color);
int					ft_loop(void);
void				ft_recv(void);
int					ft_send(void);
int					ft_compare_mac(unsigned char *mac1, unsigned char *mac2);
int					ft_compare_ip(unsigned char *ip1, unsigned char *ip2);

#endif
