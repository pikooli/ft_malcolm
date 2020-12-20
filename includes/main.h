/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:00:00 by pascal            #+#    #+#             */
/*   Updated: 2020/12/20 18:43:51 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAIN_H
# define MAIN_H
# include "libft.h"
# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <ifaddrs.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

typedef struct s_mim 
{
        
}               t_min;

char        *ft_getIpAddress();
int         ft_print_error(char *str);
int ft_check_arg(int ac, char **av);

#endif
