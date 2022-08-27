/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:15:07 by npinheir          #+#    #+#             */
/*   Updated: 2021/09/06 17:52:00 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

// Main

int		main(int argc, char **argv);
void	sort_stack(t_stack *stack_a, t_stack *stack_b);

// Sort 3

void	sort_2_up(t_stack *stack_a);
void	push_sort_2_down(t_stack *stack_a, t_stack *stack_b);
void	simple_sort_3(t_stack *stack_a);
void	sort_3_up(t_stack *stack_a, t_stack *stack_b, int len);
void	push_sort_3_down(t_stack *stack_a, t_stack *stack_b, int len);
void	norm_1(t_stack *stack_a);

// Sort 5

void	simple_sort_5(t_stack *stack_a, t_stack *stack_b);
void	simple_sort_4(t_stack *stack_a, t_stack *stack_b);

// Big sort

size_t	min_index(int *tab, int tab_len, int begin, int min);
int		stack_min(int *tab, int begin, int tab_len);
int		*quick_sort(t_stack *stack, int *tab, int len);
int		get_median(t_stack *stack, int *median, int len);
int		check_sort_down(t_stack *stack);
int		big_sort_a(t_stack *stack_a, t_stack *stack_b, size_t len);
int		big_sort_b(t_stack *stack_a, t_stack *stack_b, size_t len);
int		norm_2(t_stack *stack_a, t_stack *stack_b, int len);

#endif