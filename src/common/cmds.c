/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:25:55 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 10:42:08 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	swap_a(t_stack *stack_a, int print)
{
	int	temp;

	if (stack_a && stack_a->tab && stack_a->current_size > 1)
	{
		temp = stack_a->tab[0];
		stack_a->tab[0] = stack_a->tab[1];
		stack_a->tab[1] = temp;
		if (print)
			ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_stack *stack_b, int print)
{
	int	temp;

	if (stack_b && stack_b->tab && stack_b->current_size > 1)
	{
		temp = stack_b->tab[0];
		stack_b->tab[0] = stack_b->tab[1];
		stack_b->tab[1] = temp;
		if (print)
			ft_putstr_fd("sb\n", 1);
	}
}

void	swap_swap(t_stack *stack_a, t_stack *stack_b, int print)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
}

void	push_a(t_stack *stack_a, t_stack *stack_b, int print)
{
	size_t	i;
	int		count;

	i = 0;
	count = (stack_a->current_size - 1);
	if (stack_a && stack_b && stack_b->current_size > 0)
	{
		while ((count + 1) > 0)
		{
			stack_a->tab[count + 1] = stack_a->tab[count];
			count--;
		}
		stack_a->tab[0] = stack_b->tab[0];
		while (i < (stack_b->current_size - 1))
		{
			stack_b->tab[i] = stack_b->tab[i + 1];
			i++;
		}
		stack_a->current_size++;
		stack_b->current_size--;
		if (print)
			ft_putstr_fd("pa\n", 1);
	}
}

void	push_b(t_stack *stack_b, t_stack *stack_a, int print)
{
	size_t	i;
	int		count;

	i = 0;
	count = (stack_b->current_size - 1);
	if (stack_a && stack_b && stack_a->current_size > 0)
	{
		while ((count + 1) > 0)
		{
			stack_b->tab[count + 1] = stack_b->tab[count];
			count--;
		}
		stack_b->tab[0] = stack_a->tab[0];
		while (i < (stack_a->current_size - 1))
		{
			stack_a->tab[i] = stack_a->tab[i + 1];
			i++;
		}
		stack_b->current_size++;
		stack_a->current_size--;
		if (print)
			ft_putstr_fd("pb\n", 1);
	}
}
