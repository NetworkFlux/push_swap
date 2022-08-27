/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 16:12:00 by npinheir          #+#    #+#             */
/*   Updated: 2021/09/06 17:51:47 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort_4(t_stack *stack_a, t_stack *stack_b)
{
	size_t	index;

	index = min_index(stack_a->tab, 4, 0, stack_min(stack_a->tab, 0, 4));
	if (index == 0)
	{
		push_b(stack_b, stack_a, 1);
	}
	else if (index < 3)
	{
		while (index--)
			rotate_a(stack_a, 1);
		push_b(stack_b, stack_a, 1);
	}
	else
	{
		reverse_rotate_a(stack_a, 1);
		push_b(stack_b, stack_a, 1);
	}
	simple_sort_3(stack_a);
	push_a(stack_a, stack_b, 1);
}

void	simple_sort_5(t_stack *stack_a, t_stack *stack_b)
{
	size_t	index;

	index = min_index(stack_a->tab, 5, 0, stack_min(stack_a->tab, 0, 5));
	if (index == 0)
	{
		push_b(stack_b, stack_a, 1);
	}
	else if (index < 3)
	{
		while (index--)
			rotate_a(stack_a, 1);
		push_b(stack_b, stack_a, 1);
	}
	else
	{
		while (index < 5)
		{
			reverse_rotate_a(stack_a, 1);
			index++;
		}
		push_b(stack_b, stack_a, 1);
	}
	simple_sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b, 1);
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->current_size <= 3)
		simple_sort_3(stack_a);
	else if (stack_a->current_size <= 5)
		simple_sort_5(stack_a, stack_b);
	else
		big_sort_a(stack_a, stack_b, stack_a->current_size);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count_change;
	char	**new_args;

	if (argc == 1)
		exit(0);
	count_change = 0;
	new_args = change_args(&argc, argv, &count_change);
	error_check(argc, new_args, count_change);
	stack_a = fill_stack(argc, new_args, count_change);
	stack_b = init_stack(argc, count_change);
	if (!check_sort_up(stack_a))
		sort_stack(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	return (0);
}
