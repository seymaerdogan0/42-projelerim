/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:12:39 by seerdoga          #+#    #+#             */
/*   Updated: 2024/12/14 16:01:38 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int un)
{
	int	count;

	count = 0;
	if (un >= 10)
	{
		count += ft_print_unsigned(un / 10);
	}
	count += write(1, &"0123456789"[un % 10], 1);
	return (count);
}
