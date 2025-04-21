/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:12:17 by julifern          #+#    #+#             */
/*   Updated: 2025/04/21 18:49:49 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, char *operation, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	ft_putendl_fd(operation, 1);
}

void	pa(t_stack *stack, char *operation)
{
	int	tmp;

	if (stack->b_size == 0)
			return ;
	tmp = stack->b[0];
	ft_memmove(stack->a + 1, stack->a, sizeof(int) * stack->a_size);
	stack->a[0] = tmp;
	--stack->b_size;
	ft_memmove(stack->b, stack->b + 1, sizeof(int) * stack->b_size);
	++stack->a_size;
	ft_putendl_fd(operation, 1);
}

void	pb(t_stack *stack, char *operation)
{
	int	tmp;
	
	if (stack->a_size == 0)
		return ;
	tmp = stack->a[0];
	ft_memmove(stack->b + 1, stack->b, sizeof(int) * stack->b_size);
	stack->b[0] = tmp;
	--stack->a_size;
	ft_memmove(stack->a, stack->a + 1, sizeof(int) * stack->a_size);
	++stack->b_size;
	ft_putendl_fd(operation, 1);
}

void	reverse(int *stack, char *operation, int size)
{
	int	tmp;
	
	tmp = stack[size - 1];
	ft_memmove(stack + 1, stack, sizeof(int) * (size - 1));
	stack[0] = tmp;
	write(1, "rr", 2);
	ft_putendl_fd(operation, 1);
}

void	rotate(int *stack, char *operation, int size)
{
	int	tmp;

	tmp = stack[0];
	ft_memmove(stack, stack + 1, sizeof(int) * (size - 1));
	stack[size - 1] = tmp;
	write(1, "r", 1);
	ft_putendl_fd(operation, 1);
}