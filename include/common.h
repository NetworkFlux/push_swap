/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:58:27 by npinheir          #+#    #+#             */
/*   Updated: 2021/08/14 18:34:27 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"

# define INT_MAX 2147483647

typedef struct s_stack
{
	int		*tab;
	size_t	current_size;
	size_t	max_size;
}	t_stack;

// Commands

void	swap_a(t_stack *stack_a, int print);
void	swap_b(t_stack *stack_b, int print);
void	swap_swap(t_stack *stack_a, t_stack *stack_b, int print);
void	push_a(t_stack *stack_a, t_stack *stack_b, int print);
void	push_b(t_stack *stack_b, t_stack *stack_a, int print);
void	rotate_a(t_stack *stack_a, int print);
void	rotate_b(t_stack *stack_b, int print);
void	rotate_rotate(t_stack *stack_a, t_stack *stack_b, int print);
void	reverse_rotate_a(t_stack *stack_a, int print);
void	reverse_rotate_b(t_stack *stack_b, int print);
void	reverse_rotate_rotate(t_stack *stack_a, t_stack *stack_b, int print);

// Initialize stacks

t_stack	*init_stack(int count, int count_change);
t_stack	*fill_stack(int count, char **values, int count_change);
char	**change_args(int *count, char **values, int *count_change);

// Utils

int		has_space(char *str);
int		*tab_copy(t_stack *src, int *dest, int len);

// Free

void	free_stack(t_stack *stack_a, t_stack *stack_b);

// Check sort

int		check_sort_up(t_stack *stack);

// Errors

int		error_check1(int count, char **values, int count_change);
int		error_check2(int count, char **values, int count_change);
int		error_check3(int count, char **values, int count_change);
void	error_check(int count, char **values, int count_change);
void	print_error(void);
int		countwords(char const *s, char c);

#endif