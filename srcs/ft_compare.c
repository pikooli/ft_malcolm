/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 00:45:23 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 00:52:51 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


int ft_compare_ip(unsigned char *ip1, unsigned char *ip2)
{
	if (ip1[0] == ip2[0] &&
		ip1[1] == ip2[1] &&
		ip1[2] == ip2[2] &&
		ip1[3] == ip2[3]
	)
		return (1);
	return (0);
}

int ft_compare_mac(unsigned char *mac1, unsigned char *mac2)
{
	if (mac1[0] == mac2[0] &&
		mac1[1] == mac2[1] &&
		mac1[2] == mac2[2] &&
		mac1[3] == mac2[3] &&
		mac1[4] == mac2[4] &&
		mac1[5] == mac2[5]
	)
		return (1);
	return (0);
}