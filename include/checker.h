/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:35:21 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/14 18:34:45 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// Checker

int		main(int argc, char **argv);
int		checker(t_stack *stack_a, t_stack *stack_b);
int		get_instruction(t_stack *stack_a, t_stack *stack_b, char *instr);

// Utils

void	print_good(void);
void	print_bad(void);

// Get next line

int		get_next_linec(int fd, char **line);
int		get_next_l(int fd, char **line, unsigned int size);
char	*free_reste(char *reste, int *ret, int j);
char	*ft_strjoinplus(char *reste, char *buff, int ret);
char	*get_line(char *reste);
int		is_linec(char *save);
int		ft_strlen2c(char *str);
void	norme_gnlc(char *reste, int i, int *j, char *new);

#endif