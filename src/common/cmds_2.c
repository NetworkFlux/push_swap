/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:08:40 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 10:41:52 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	rotate_a(t_stack *stack_a, int print)
{
	int		temp;
	size_t	i;

	if (stack_a && stack_a->current_size > 1)
	{
		i = 1;
		temp = stack_a->tab[0];
		while (i < stack_a->current_size)
		{
			stack_a->tab[i - 1] = stack_a->tab[i];
			i++;
		}
		stack_a->tab[stack_a->current_size - 1] = temp;
		if (print)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_b(t_stack *stack_b, int print)
{
	int		temp;
	size_t	i;

	if (stack_b && stack_b->current_size > 1)
	{
		i = 1;
		temp = stack_b->tab[0];
		while (i < stack_b->current_size)
		{
			stack_b->tab[i - 1] = stack_b->tab[i];
			i++;
		}
		stack_b->tab[stack_b->current_size - 1] = temp;
		if (print)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_rotate(t_stack *stack_a, t_stack *stack_b, int print)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

void	reverse_rotate_a(t_stack *stack_a, int print)
{
	int	temp;
	int	i;

	if (stack_a && stack_a->current_size > 1)
	{
		temp = stack_a->tab[stack_a->current_size - 1];
		i = (stack_a->current_size - 1);
		while (i > 0)
		{
			stack_a->tab[i] = stack_a->tab[i - 1];
			i--;
		}
		stack_a->tab[0] = temp;
		if (print)
			ft_putstr_fd("rra\n", 1);
	}
}

void	reverse_rotate_b(t_stack *stack_b, int print)
{
	int	temp;
	int	i;

	if (stack_b && stack_b->current_size > 1)
	{
		temp = stack_b->tab[stack_b->current_size - 1];
		i = (stack_b->current_size - 1);
		while (i > 0)
		{
			stack_b->tab[i] = stack_b->tab[i - 1];
			i--;
		}
		stack_b->tab[0] = temp;
		if (print)
			ft_putstr_fd("rrb\n", 1);
	}
}
