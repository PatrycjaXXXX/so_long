/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:20:42 by psmolich          #+#    #+#             */
/*   Updated: 2025/08/27 06:42:44 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

static void	ft_receive_byte(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned int		bit;
	static unsigned char	byte;
	static int				signal;

	(void)ucontext;
	signal = SIGUSR1;
	if (sig == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &byte, 1);
		if (byte == '\0')
		{
			signal = SIGUSR2;
			write(1, "\n", 1);
		}
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, signal);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("%i\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_receive_byte;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
