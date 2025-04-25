/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:40:46 by seerdoga          #+#    #+#             */
/*   Updated: 2025/03/23 13:20:11 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	send_signal(int pid, char *str)
{
	int		bit;
	char	c;
	int		i;

	i = 0;
	bit = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		while (bit < 8)
		{
			if (c & 0b00000001)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			c >>= 1;
			bit++;
			usleep(70);
		}
		i++;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("client: invalid arguments\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	send_signal(pid, av[2]);
	return (0);
}
