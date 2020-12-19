/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 21:00:00 by pascal            #+#    #+#             */
/*   Updated: 2020/12/18 21:26:29 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAIN_H
# define MAIN_H
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

char	*ft_strdup(const char *s1);
char * getIpAddress();
int ft_strcmp(char *str1, char *str2);


int test();


#endif
