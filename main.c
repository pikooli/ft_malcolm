/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:11:37 by pascal            #+#    #+#             */
/*   Updated: 2020/12/20 21:47:55 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int ft_init_struct(char **av)
{
    mim.source_ip = av[1];
    mim.source_mac = av[2];
    mim.dest_ip = av[3];
    mim.dest_mac = av[4];
    mim.socket = -1;
    if ((mim.buffer = (void *)malloc(BUF_SIZE)) == NULL)
        return (1);
    mim.etherhead = mim.buffer;
    mim.eh = (struct ethhdr *) mim.buffer;
    mim.arphead = mim.buffer + 14;
    return (0);
}


int main(int ac, char **av)
{
    (void)ac;
    (void)av;   
    if (ft_check_arg(ac, av))
    {
        system("leaks a.out");
        return (0);
    }
    if(ft_init_struct(av))
        return (ft_print_error("Malloc went wrong"));
    ft_getIpAddress();
    ft_mim();
    system("leaks a.out");
    return 0;
}