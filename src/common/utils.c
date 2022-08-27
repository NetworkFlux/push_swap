/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:20:12 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 10:44:16 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == ' ')
			return (1);
	}
	return (0);
}

int	*tab_copy(t_stack *src, int *dest, int len)
{
	int	i;

	i = 0;
	if (src && dest)
	{
		while (i < len)
		{
			dest[i] = src->tab[i];
			i++;
		}
	}
	return (dest);
}

int	countwords(char const *s, char c)
{
	int		count;
	int		i;

	if (!s || !s[0])
		return (0);
	count = 0;
	if (s[0] != c)
		count = 1;
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}
