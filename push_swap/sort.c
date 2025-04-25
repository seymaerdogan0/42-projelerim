/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:55:27 by seerdoga          #+#    #+#             */
/*   Updated: 2025/03/25 19:36:37 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head)
{
	int	biggest;

	biggest = find_biggest(*head);
	if ((*head)->index == biggest)
		rotate_a(head);
	else if ((*head)->next->index == biggest)
		r_rotate_a(head);
	if ((*head)->index > (*head)->next->index)
		swap_a(head);
}

void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	push_count;
	int	smallest_index;

	push_count = 0;
	smallest_index = 0;
	while (size - push_count > 3)
	{
		i = 0;
		if ((*stack_a)->index == smallest_index)
		{
			push_b(stack_a, stack_b);
			push_count++;
			smallest_index++;
		}
		else
			rotate_a(stack_a);
	}
}

void	radix_pass(t_stack **stack_a, t_stack **stack_b, int size, int bit)
{
	int	j;

	j = 0;
	while (j++ < size)
	{
		if (((*stack_a)->index >> bit) & 1)
			rotate_a(stack_a);
		else
			push_b(stack_a, stack_b);
	}
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	sort_all(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	max_bits;
	int	b_size;

	if (size <= 50)
	{
		push_smallest_to_b(stack_a, stack_b, size);
		sort_three(stack_a);
		b_size = count_nodes(*stack_b);
		while (b_size--)
			push_a(stack_a, stack_b);
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap_a(stack_a);
		return ;
	}
	max_bits = find_bits(find_biggest(*stack_a));
	i = 0;
	while (i < max_bits)
		radix_pass(stack_a, stack_b, size, i++);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (sorted(stack_a))
		return ;
	size = count_nodes(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else
		sort_all(stack_a, stack_b, size);
}
