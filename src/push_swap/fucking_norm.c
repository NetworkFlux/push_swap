/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fucking_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:59:58 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 11:11:02 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_1(t_stack *stack_a)
{
	if (stack_a->tab[0] < stack_a->tab[2])
	{
		swap_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else
		reverse_rotate_a(stack_a, 1);
}

int	norm_2(t_stack *stack_a, t_stack *stack_b, int len)
{
	push_sort_3_down(stack_a, stack_b, len);
	return (1);
}
