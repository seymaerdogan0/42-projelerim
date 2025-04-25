/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:09:56 by seerdoga          #+#    #+#             */
/*   Updated: 2024/10/28 13:09:56 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n, int sign)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (sign < 0)
		i++;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nmb;
	int		sign;
	int		digit;

	nmb = n;
	sign = 1;
	if (nmb < 0)
	{
		sign = -1;
	}
	nmb = nmb * sign;
	digit = ft_digit(nmb, sign);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit] = '\0';
	while (digit > 0)
	{
		str[--digit] = (nmb % 10) + '0';
		nmb = nmb / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
