/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seerdoga <seerdoga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 14:46:44 by seerdoga          #+#    #+#             */
/*   Updated: 2025/03/25 19:37:59 by seerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack {
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*put_it_list(char **argv);
void	set_index(t_stack *head, int link_size);

int		count_nodes(t_stack *head);
void	show_list(t_stack *head);
void	insert_at_list(t_stack **head, int new_value);
t_stack	*make_new_node(int new_value);

void	swap(t_stack **head);
void	swap_a(t_stack **head);
void	swap_b(t_stack **head);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **stack_from, t_stack **stack_to);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_cw(t_stack **head);
void	rotate_a(t_stack **head);
void	rotate_b(t_stack **head);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	rotate_ccw(t_stack **head);
void	r_rotate_a(t_stack **head);
void	r_rotate_b(t_stack **head);
void	r_rotate_ab(t_stack **stack_a, t_stack **stack_b);

int		find_biggest(t_stack *head);
int		find_bits(int biggest_nbr);
void	sort_three(t_stack **head);
void	sort_all(t_stack **stack_a, t_stack **stack_b, int size);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b, int size);
void	radix_pass(t_stack **stack_a, t_stack **stack_b, int size, int bit);
int		sorted(t_stack **head);

void	input_control(char **argv);
int		nbr_control(char *argv);
int		double_control(char **argv);
void	print_error(char *str, char **to_free);
void	free_stack(t_stack **head);
int		count_arg(char **array);
void	ft_free(char **arr);
char	**seperate_argv(char **av);
char	*all_in_one(const char *s1, const char *s2);
long	ft_atol(const char *str);
int		is_all_whitespace(const char *str);

#endif
