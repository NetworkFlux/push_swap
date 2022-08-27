/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:33:00 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/14 18:35:55 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_atoi2(const char *str, int *sign)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			*sign *= (-1);
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	res;

	sign = 1;
	res = ft_atoi2(str, &sign);
	if (res > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		if (sign == -1)
			return (0);
	}
	return ((int)res * sign);
}
