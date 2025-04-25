/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:14:59 by seerdoga          #+#    #+#             */
/*   Updated: 2025/03/25 19:38:42 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_control(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	nbr_control(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-')
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	input_control(char **argv)
{
	char	**tmp_array;
	int		i;
	long	tmp_val;

	if (is_all_whitespace(argv[1]))
		print_error("ERROR", NULL);
	tmp_array = seperate_argv(argv);
	i = 0;
	if (!tmp_array || !tmp_array[0] || ft_strlen(tmp_array[i]) > 11)
		print_error("ERROR", tmp_array);
	while (tmp_array[i])
	{
		if (tmp_array[i][0] == '\0')
			print_error("ERROR", tmp_array);
		tmp_val = ft_atol(tmp_array[i]);
		if (tmp_val < -2147483648 || tmp_val > 2147483647)
			print_error("ERROR", tmp_array);
		if (!nbr_control(tmp_array[i]))
			print_error("ERROR", tmp_array);
		i++;
	}
	if (double_control(tmp_array))
		print_error("ERROR", tmp_array);
	ft_free(tmp_array);
}

int	is_all_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}
