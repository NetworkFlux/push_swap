/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:03:57 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/13 10:40:13 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_good(void)
{
	write(1, "OK\n", 3);
	exit(0);
}

void	print_bad(void)
{
	write(1, "KO\n", 3);
	exit(0);
}

char	*free_reste(char *reste, int *ret, int j)
{
	char	*new;
	int		i;

	*ret = 0;
	i = is_linec(reste);
	if (i < 0)
	{
		if (i == -1)
			free(reste);
		return (0);
	}
	new = (char *)malloc((ft_strlen2c(reste) - i + 1) * sizeof(char));
	if (!new)
	{
		*ret = -1;
		free(reste);
		return (0);
	}
	i++;
	norme_gnlc(reste, i, &j, new);
	new[j] = '\0';
	free(reste);
	return (new);
}

int	get_next_l(int fd, char **line, unsigned int size)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*reste[FOPEN_MAX];
	int			ret;

	if (read(fd, buff, 0) < 0)
		return (-1);
	*line = NULL;
	ret = 1;
	while (is_linec(reste[fd]) < 0 && ret)
	{
		ret = read(fd, buff, size);
		reste[fd] = ft_strjoinplus(reste[fd], buff, ret);
		if (!reste[fd])
			return (-1);
	}
	*line = get_line(reste[fd]);
	if (!*line)
		return (-1);
	reste[fd] = free_reste(reste[fd], &ret, 0);
	if (!reste[fd])
		return (-1);
	return (1);
}

int	get_next_linec(int fd, char **line)
{
	unsigned int	size;

	if (BUFFER_SIZE <= 0 || !line || fd > FOPEN_MAX)
		return (-1);
	size = BUFFER_SIZE;
	size += 1;
	return (get_next_l(fd, line, size));
}
