/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:02:25 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/14 19:31:00 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fucking_norm(t_stack *stack_a, t_stack *stack_b, size_t *len)
{
	while ((*len)--)
		push_a(stack_a, stack_b, 1);
	return (1);
}

int	big_sort_b(t_stack *stack_a, t_stack *stack_b, size_t len)
{
	int		median;
	int		push_under;
	size_t	elem;

	push_under = 0;
	elem = len;
	if (check_sort_down(stack_b))
		return (fucking_norm(stack_a, stack_b, &len));
	if (len <= 3)
		return (norm_2(stack_a, stack_b, len));
	if (!get_median(stack_b, &median, len))
		return (0);
	while (len != elem / 2)
	{
		if (stack_b->tab[0] >= median && len--)
			push_a(stack_a, stack_b, 1);
		else if (++push_under)
			rotate_b(stack_b, 1);
	}
	while (elem / 2 != stack_b->current_size && push_under--)
		reverse_rotate_b(stack_b, 1);
	return (big_sort_a(stack_a, stack_b, elem / 2 + elem % 2)
		&& big_sort_b(stack_a, stack_b, elem / 2));
}

static int	fucking_norm_2(t_stack *stack_a, t_stack *stack_b, int len)
{
	sort_3_up(stack_a, stack_b, len);
	return (1);
}

int	big_sort_a(t_stack *stack_a, t_stack *stack_b, size_t len)
{
	int		median;
	int		push_under;
	size_t	elem;

	elem = len;
	push_under = 0;
	if (check_sort_up(stack_a))
		return (1);
	if (len <= 3)
		return (fucking_norm_2(stack_a, stack_b, len));
	if (!get_median(stack_a, &median, len))
		return (0);
	while (len != elem / 2 + elem % 2)
	{
		if (stack_a->tab[0] < median && len--)
			push_b(stack_b, stack_a, 1);
		else if (++push_under)
			rotate_a(stack_a, 1);
	}
	while (elem / 2 + elem % 2 != stack_a->current_size && push_under--)
		reverse_rotate_a(stack_a, 1);
	return (big_sort_a(stack_a, stack_b, elem / 2 + elem % 2)
		&& big_sort_b(stack_a, stack_b, elem / 2));
	return (1);
}
