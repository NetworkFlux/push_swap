/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:26:31 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/15 15:52:15 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_instruction(t_stack *stack_a, t_stack *stack_b, char *instr)
{
	if (!(ft_strncmp(instr, "sa", 3)))
		swap_a(stack_a, 0);
	else if (!(ft_strncmp(instr, "sb", 3)))
		swap_b(stack_b, 0);
	else if (!(ft_strncmp(instr, "ss", 3)))
		swap_swap(stack_a, stack_b, 0);
	else if (!(ft_strncmp(instr, "pa", 3)))
		push_a(stack_a, stack_b, 0);
	else if (!(ft_strncmp(instr, "pb", 3)))
		push_b(stack_b, stack_a, 0);
	else if (!(ft_strncmp(instr, "ra", 3)))
		rotate_a(stack_a, 0);
	else if (!(ft_strncmp(instr, "rb", 3)))
		rotate_b(stack_b, 0);
	else if (!(ft_strncmp(instr, "rr", 3)))
		rotate_rotate(stack_a, stack_b, 0);
	else if (!(ft_strncmp(instr, "rra", 4)))
		reverse_rotate_a(stack_a, 0);
	else if (!(ft_strncmp(instr, "rrb", 4)))
		reverse_rotate_b(stack_b, 0);
	else if (!(ft_strncmp(instr, "rrr", 4)))
		reverse_rotate_rotate(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

int	checker(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	char	*instr;

	instr = NULL;
	i = 1;
	while (1)
	{
		if (get_next_linec(0, &instr) == -1)
			break ;
		if (!get_instruction(stack_a, stack_b, instr))
		{
			i = 0;
			break ;
		}
		free(instr);
	}
	if (!i)
		print_error();
	else if (!stack_a && !stack_b)
		exit(0);
	else if (!check_sort_up(stack_a) || stack_b->current_size)
		print_bad();
	else
		print_good();
	return (1);
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
	stack_a = fill_stack(argc, argv, count_change);
	stack_b = init_stack(argc, count_change);
	checker(stack_a, stack_b);
	free_stack(stack_a, stack_b);
	exit(0);
	return (0);
}
