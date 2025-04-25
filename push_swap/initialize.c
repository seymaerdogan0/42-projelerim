/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:04:37 by seerdoga          #+#    #+#             */
/*   Updated: 2025/03/25 16:44:34 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *head, int link_size)
{
	t_stack	*biggest;
	t_stack	*tmp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL
					|| tmp->value > biggest->value))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = link_size;
	}
}

t_stack	*put_it_list(char **argv)
{
	t_stack	*stack_a;
	char	**tmp_array;
	int		i;
	int		val;

	stack_a = NULL;
	i = 0;
	tmp_array = seperate_argv(argv);
	if (!tmp_array)
		print_error("ERROR", NULL);
	while (tmp_array[i])
	{
		val = ft_atoi(tmp_array[i]);
		insert_at_list(&stack_a, val);
		i++;
	}
	ft_free(tmp_array);
	return (stack_a);
}
