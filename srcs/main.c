/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:11:37 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 01:46:22 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_prepare_ip(char *ip, unsigned char tab[4])
{
    char **tmp;
    int i;
    
    if ((tmp = ft_split(ip, '.')) == NULL)
        return (ft_print_error("Malloc went wrong"));
    i = -1;
    while (tmp[++i])
        tab[i] = ft_atoi(tmp[i]);
    return (0);
}

int ft_prepare_mac(char *mac, unsigned char tab[6])
{
    char **tmp;
    int i;
    int a;

    if ((tmp = ft_split(mac, ':')) == NULL)
        return (ft_print_error("Malloc went wrong"));
    i = -1;
    while (tmp[++i])
    {
        a = -1;
        while(tmp[i][++a])
            tmp[i][a] = ft_tolower(tmp[i][a]);
        tab[i] = ft_atoi_base(tmp[i], "0123456789abcdef");
    }
    return (0);
}

int ft_init_struct(char **av)
{
    mim.source_ip = av[1];
    if (ft_prepare_ip(av[1], mim.source_ip_tab))
        return (1);
    ft_print_ip("Source ip copied", mim.source_ip_tab);
    mim.source_mac = av[2];
    if (ft_prepare_mac(av[2], mim.source_mac_tab))
        return (1);
    ft_print_mac("Source mac copied", mim.source_mac_tab);
    mim.dest_ip = av[3];
    if (ft_prepare_ip(av[3], mim.dest_ip_tab))
        return (1);
    ft_print_ip("Dest Ip copied", mim.dest_ip_tab);
    mim.dest_mac = av[4];
    if (ft_prepare_mac(av[4], mim.dest_mac_tab))
        return (1);
    ft_print_mac("Dest mac copied", mim.dest_mac_tab);
    mim.socket = -1;
    if ((mim.buffer = (void *)malloc(BUF_SIZE)) == NULL)
        return (1);
    mim.etherhead = mim.buffer;
    mim.eh = (struct ethhdr *) mim.buffer;
    mim.arphead = mim.buffer + 14;
    mim.ifindex = 0;
    return (0);
}


int main(int ac, char **av)
{
    (void)ac;
    (void)av;   

    // test();
    if (ft_check_arg(ac, av))
    {
        // system("leaks a.out");
        return (0);
    }
    if(ft_init_struct(av))
        return (ft_print_error("Malloc went wrong"));
    ft_mim();
    // system("leaks a.out");
    return 0;
}