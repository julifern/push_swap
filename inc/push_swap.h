/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:34:37 by julifern          #+#    #+#             */
/*   Updated: 2025/04/23 17:05:01 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/inc/libft.h"
# include "ft_printf/inc/ft_printf.h"

// struct

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	**args;
}	t_stack;

// functions

int		error_msg(t_stack *stack);

// parsing_args

int		has_overflow(char *str);
int		is_valid(char **args);
char	**get_args(char **array);

// parsing_stack

int		is_duplicate(t_stack *stack, int *array);
int		is_array_sorted(int *array, int size);
void	init_stacks(t_stack *stack);
void	fill_stack(t_stack *stack, char **args);

// operations

void	swap(int *stack, char *operation, int size);
void	pa(t_stack *stack, char *operation);
void	pb(t_stack *stack, char *operation);
void	reverse(int *stack, char *operation, int size);
void	rotate(int *stack, char *operation, int size);

// sort

void	sort_three_size(t_stack *stack);
void	sort_four_to_five_size(t_stack *stack);
void	radix_sort(t_stack *stack);

// utils

void	free_all(t_stack *stack);
void	index_stack(t_stack *stack);

#endif