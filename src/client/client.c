/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:46:06 by emauduit          #+#    #+#             */
/*   Updated: 2023/12/16 16:41:50 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_putstr_fd("Please write: ./client [PID] [string]\n", 2);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, &sigclient);
	signal(SIGUSR2, &sigclient);
	pid = ft_atoi(av[1]);
	if (pid <= 0 || ft_isdigit(av[1]))
	{
		ft_putstr_fd("Invalid PID: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd("\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_send_string(pid, av[2]);
	return (0);
}
