/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:34:40 by seerdoga          #+#    #+#             */
/*   Updated: 2024/12/14 16:00:04 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_put_hex(unsigned int num, const char format)
{
	char	c;

	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			c = num + '0';
		else
		{
			if (format == 'x')
				c = num - 10 + 'a';
			else if (format == 'X')
				c = num - 10 + 'A';
		}
		write(1, &c, 1);
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	print_length;

	print_length = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		ft_put_hex(num, format);
		print_length = ft_hex_len(num);
	}
	return (print_length);
}
