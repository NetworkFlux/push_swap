/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:14:32 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 10:43:21 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	error_check1(int count, char **values, int count_change)
{
	int	i;
	int	j;

	i = 1;
	if (count_change)
		i = 0;
	while (i < count - count_change)
	{
		if (!(values[i][0] == 45 || (values[i][0] >= 48 && values[i][0] <= 57)))
			return (1);
		if ((values[i][0] == 45) && !(values[i][1]))
			return (1);
		j = 1;
		while (values[i][j])
		{
			if (values[i][j] < 48 || values[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check2(int count, char **values, int count_change)
{
	int	i;
	int	j;

	i = 1;
	if (count_change)
		i = 0;
	while (i < count - count_change)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(values[i], values[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	error_check3(int count, char **values, int count_change)
{
	int	i;

	i = 1;
	if (count_change)
		i = 0;
	while (i < count - count_change)
	{
		if (atol(values[i]) > 2147483647 || atol(values[i]) < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	error_check(int count, char **values, int count_change)
{
	if (error_check1(count, values, count_change)
		|| error_check2(count, values, count_change)
		|| error_check3(count, values, count_change))
		print_error();
}
