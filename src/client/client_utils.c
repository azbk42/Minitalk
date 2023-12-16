/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:46:03 by emauduit          #+#    #+#             */
/*   Updated: 2023/12/16 16:45:30 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_bit_flag;

void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		g_bit_flag = 0;
		if (kill(pid, 0) == -1)
		{
			ft_putstr_fd("Error: Wrong PID", 2);
			exit(EXIT_FAILURE);
		}
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_bit_flag == 0)
			usleep(100);
	}
}

void	sigclient(int signum)
{
	if (signum == SIGUSR1)
		g_bit_flag = 1;
	else if (signum == SIGUSR2)
	{
		ft_printf("\nThe server has successfully received the message.\n\n");
		exit(0);
	}
}

void	ft_send_string(int pid, const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_send_char(pid, str[i]);
	ft_send_char(pid, '\n');
	ft_send_char(pid, '\0');
}
