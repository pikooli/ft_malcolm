/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:11:28 by pascal            #+#    #+#             */
/*   Updated: 2020/12/20 21:49:26 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_mim()
{
	ft_print("min going to proceed");
	mim.socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	if (mim.socket == -1)
		return (ft_print_error("socket didn't create"));
	ft_printf("socket create at : %d\n", mim.socket);
	

	close(mim.socket);
	return (0);
}