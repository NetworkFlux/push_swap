/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 09:41:14 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 11:01:58 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_up(t_stack *stack_a)
{
	if (stack_a->tab[0] > stack_a->tab[1])
		swap_a(stack_a, 1);
}

void	push_sort_2_down(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->tab[0] < stack_b->tab[1])
		swap_b(stack_b, 1);
	push_a(stack_a, stack_b, 1);
	push_a(stack_a, stack_b, 1);
}

void	simple_sort_3(t_stack *stack_a)
{
	if (stack_a->current_size == 2)
		sort_2_up(stack_a);
	else if (stack_a->tab[0] > stack_a->tab[1]
		&& stack_a->tab[1] < stack_a->tab[2])
	{
		if (stack_a->tab[0] > stack_a->tab[2])
			rotate_a(stack_a, 1);
		else
			swap_a(stack_a, 1);
	}
	else if (stack_a->tab[0] < stack_a->tab[1]
		&& stack_a->tab[1] > stack_a->tab[2])
		norm_1(stack_a);
	else if (stack_a->tab[0] > stack_a->tab[1]
		&& stack_a->tab[1] > stack_a->tab[2])
	{
		swap_a(stack_a, 1);
		reverse_rotate_a(stack_a, 1);
	}
}

void	sort_3_up(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 2)
		return (sort_2_up(stack_a));
	else if (len == 3)
	{
		while (len != 3 || !(stack_a->tab[0] < stack_a->tab[1]
				&& stack_a->tab[1] < stack_a->tab[2]))
		{
			if (len == 3 && stack_a->tab[0] > stack_a->tab[1]
				&& stack_a->tab[2])
				swap_a(stack_a, 1);
			else if (len == 3 && !(stack_a->tab[2] > stack_a->tab[0]
					&& stack_a->tab[2] > stack_a->tab[1]))
			{
				push_b(stack_b, stack_a, 1);
				len--;
			}
			else if (stack_a->tab[0] > stack_a->tab[1])
				swap_a(stack_a, 1);
			else if (len++)
				push_a(stack_a, stack_b, 1);
		}
	}
}

void	push_sort_3_down(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 1)
		push_a(stack_a, stack_b, 1);
	else if (len == 2)
		return (push_sort_2_down(stack_a, stack_b));
	else if (len == 3)
	{
		while (len || !(stack_a->tab[0] < stack_a->tab[1]
				&& stack_a->tab[1] < stack_a->tab[2]))
		{
			if (len == 1 && stack_a->tab[0] > stack_a->tab[1])
				swap_a(stack_a, 1);
			else if (len == 1 || (len >= 2 && stack_b->tab[0] > stack_b->tab[1])
				|| (len == 3 && stack_b->tab[0] > stack_b->tab[2]))
			{
				push_a(stack_a, stack_b, 1);
				len--;
			}
			else
				swap_b(stack_b, 1);
		}
	}
}
