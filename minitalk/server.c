/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:02:11 by seerdoga          #+#    #+#             */
/*   Updated: 2025/03/23 13:17:13 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	man_signal(int signal)
{
	static int				i = 0;
	static unsigned char	binary;
	static unsigned char	bit;

	if (signal == SIGUSR1)
	{
		binary = 1;
		bit = bit | (binary << i);
		i++;
	}
	else if (signal == SIGUSR2)
	{
		i++;
	}
	if (i == 8)
	{
		write(1, &bit, 1);
		bit = 0;
		i = 0;
	}
}

static void	ft_sig(void)
{
	struct sigaction	a;

	sigemptyset(&a.sa_mask);
	sigaddset(&a.sa_mask, SIGUSR1);
	sigaddset(&a.sa_mask, SIGUSR2);
	a.sa_handler = &man_signal;
	sigaction(SIGUSR1, &a, NULL);
	sigaction(SIGUSR2, &a, NULL);
}

int	main(void)
{
	ft_printf("Your pid is: %d\n", getpid());
	ft_sig();
	while (1)
		pause();
	return (0);
}
