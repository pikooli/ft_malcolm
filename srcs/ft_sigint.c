/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pascal <pascal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 21:17:13 by pascal            #+#    #+#             */
/*   Updated: 2020/12/21 03:43:57 by pascal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_sigint(int i)
{
	if (g_mim.socket == -1)
		return ;
	close(g_mim.socket);
	if (g_mim.buffer)
		free(g_mim.buffer);
	ft_printcolor("Closing MIM", "red");
	i = getuid();
	kill(i, SIGQUIT);	
}
