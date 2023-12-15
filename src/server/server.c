
#include "minitalk.h"
#include <signal.h>



static void	ft_handle_signal(int signum, siginfo_t *siginfo, void *context)
{
	static int bit_count = 0;
    static char character = 0;

    (void)context;

    character = character << 1;
    
    if (signum == SIGUSR1)
        character |= 1;
    bit_count++;
    if (bit_count >= 8) 
    {
        if (character)
            ft_putchar_fd(character, 1);
        else
            kill(siginfo->si_pid, SIGUSR2);
        character = 0;
        bit_count = 0; 
    }
	kill(siginfo->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = ft_handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
