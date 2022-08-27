/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:31:53 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 10:41:36 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	check_sort_up(t_stack *stack)
{
	size_t	i;

	i = 0;
	if (!stack)
		return (0);
	if (stack->current_size == 1)
		return (1);
	while (i < (stack->current_size - 1))
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
