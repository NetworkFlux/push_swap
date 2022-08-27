/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:29:50 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 10:40:18 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	norme_gnlc(char *reste, int i, int *j, char *new)
{
	while (reste[i + *j])
	{
		new[*j] = reste[i + *j];
		(*j)++;
	}
}

int	ft_strlen2c(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_linec(char *save)
{
	int	i;

	if (!save)
		return (-1);
	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_line(char *reste)
{
	int		i;
	char	*line;

	i = 0;
	while (reste && reste[i] && reste[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (reste && reste[i] && reste[i] != '\n')
	{
		line[i] = reste[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strjoinplus(char *reste, char *buff, int ret)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc((ft_strlen2c(reste) + ret + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while (reste && reste[i])
	{
		new[i] = reste[i];
		i++;
	}
	j = 0;
	while (j < ret)
	{
		new[i + j] = buff[j];
		j++;
	}
	new[i + j] = '\0';
	if (reste)
		free(reste);
	return (new);
}
