#include "minitalk.h"


int bit_global;


void	ft_send_char(int pid, unsigned char c)
{
	int	i;

	i = 8;
	while (--i >= 0)
	{
		bit_global = 0;
		if (kill(pid, 0) == -1)
		{
			ft_putstr_fd("Error: Wrong PID", 2);
			exit(EXIT_FAILURE);
		}
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (bit_global == 0)
			usleep(100);
	}
}

void	sigclient(int signum)
{
	if (signum == SIGUSR1)
		bit_global = 1;
	else if (signum == SIGUSR2)
	{
		ft_printf("\nServer receive correctly your message !\n\n");
		exit(0);
	}
}

void	ft_send_string(int pid, const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_send_char(pid, str[i]);
	ft_send_char(pid, '\n');
	ft_send_char(pid, '\0');
}
