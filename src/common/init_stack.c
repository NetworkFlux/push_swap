/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:13:44 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/14 19:16:05 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

char	**change_args(int *count, char **values, int *count_change)
{
	char	**new_values;

	new_values = values;
	if (*count == 2)
	{
		if (has_space(values[1]) && ft_strlen(values[1]) > 1)
		{
			new_values = ft_split(values[1], ' ');
			*count = countwords(values[1], ' ');
			*count_change = 1;
		}
	}
	return (new_values);
}

t_stack	*init_stack(int count, int count_change)
{
	t_stack	*stack;

	if (count < 2)
		return (NULL);
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->tab = malloc(sizeof(int) * count - !(count_change));
	if (!stack->tab)
		return (NULL);
	stack->current_size = 0;
	stack->max_size = count - 1;
	return (stack);
}

t_stack	*fill_stack(int count, char **values, int count_change)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = init_stack(count, count_change);
	if (!stack)
		return (NULL);
	while (i < count - !(count_change))
	{
		stack->tab[i] = ft_atoi(values[i + !(count_change)]);
		stack->current_size++;
		i++;
	}
	return (stack);
}
