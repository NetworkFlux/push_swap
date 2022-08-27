/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:47:54 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/14 19:37:21 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(int *tab, int begin, int tab_len)
{
	int	min;

	if (tab_len < 1)
		return (0);
	min = tab[begin];
	begin++;
	while (begin < tab_len)
	{
		if (tab[begin] < min)
			min = tab[begin];
		begin++;
	}
	return (min);
}

size_t	min_index(int *tab, int tab_len, int begin, int min)
{
	while (begin < tab_len)
	{
		if (tab[begin] == min)
			return (begin);
		begin++;
	}
	return (0);
}

int	*quick_sort(t_stack *stack, int *tab, int len)
{
	int		i;
	size_t	min_i;
	int		min;
	int		temp;

	i = 0;
	tab = tab_copy(stack, tab, len);
	while (i < len - 1)
	{
		min = stack_min(tab, i, len);
		min_i = min_index(tab, len, i, min);
		temp = tab[i];
		tab[i] = tab[min_i];
		tab[min_i] = temp;
		i++;
	}
	return (tab);
}

int	get_median(t_stack *stack, int *median, int len)
{
	int	*sorted_list;

	if (stack->current_size > 3)
	{
		sorted_list = (int *)malloc(sizeof(int) * len);
		if (!sorted_list)
			return (0);
		sorted_list = quick_sort(stack, sorted_list, len);
		*median = sorted_list[len / 2];
		free(sorted_list);
	}
	return (1);
}

int	check_sort_down(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < (stack->current_size - 1))
	{
		if (stack->tab[i] < stack->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
