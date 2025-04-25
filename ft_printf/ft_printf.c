/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:12:39 by seerdoga          #+#    #+#             */
/*   Updated: 2024/12/27 17:50:20 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_invalid_format(char f)
{
	int	counter;

	counter = 0;
	counter += ft_print_char('%');
	if (f > '0' && f < '9')
	{
		counter += ft_print_char(f);
	}
	return (counter);
}

int	ft_formats(va_list args, const char format)
{
	int	counter;

	counter = 0;
	if (format == 'c')
		counter += ft_print_char(va_arg(args, int));
	else if (format == 's')
		counter += ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		counter += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		counter += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		counter += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		counter += ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		counter += ft_print_percent();
	else
		counter += ft_print_invalid_format(format);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		counter;
	int		i;
	va_list	args;

	i = 0;
	counter = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			counter += ft_formats(args, str[i + 1]);
			i++;
		}
		else
		{
			counter += ft_print_char(str[i]);
		}
		i++;
	}
	va_end(args);
	return (counter);
}
