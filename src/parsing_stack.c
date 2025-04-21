/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:18:41 by julifern          #+#    #+#             */
/*   Updated: 2025/04/21 20:05:27 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_array_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		++i;
	}
	return (1);
}

void	init_stacks(t_stack *stack)
{
	stack->a_size = ft_count_array(stack->args);
	stack->b_size = 0;
	stack->a = ft_calloc(stack->a_size, sizeof(int));
	if (!stack->a)
		error_msg(stack);
	stack->b = ft_calloc(stack->a_size, sizeof(int));
	if (!stack->b)
		error_msg(stack);
}

void	fill_stack(t_stack *stack, char **args)
{
	int	i;
	
	i = 0;
	while (args[i])
	{
		stack->a[i] = ft_atoi(args[i]);
		i++;
	}
}