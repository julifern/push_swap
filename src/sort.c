/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:26:50 by julifern          #+#    #+#             */
/*   Updated: 2025/04/23 17:02:43 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_size(t_stack *stack)
{
	if (stack->a[0] == 2)
		rotate(stack->a, "a", 3);
	else if (stack->a[1] == 2)
		reverse(stack->a, "a", 3);
	if (!is_array_sorted(stack->a, stack->a_size))
		swap(stack->a, "sa", 3);
}

void	sort_four_to_five_size(t_stack *stack)
{
	while (stack->b_size <= 1)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			pb(stack, "pb");
		else
			rotate(stack->a, "a", stack->a_size);
	}
	if (stack->b[0] == 0)
		swap(stack->b, "sb", stack->b_size);
	if (stack->a[2] != 4)
	{
		if (stack->a[0] == 4)
			rotate(stack->a, "a", stack->a_size);
		else
			reverse(stack->a, "a", stack->a_size);
	}
	if (stack->a[0] > stack->a[1])
		swap(stack->a, "sa", stack->a_size);
	pa(stack, "pa");
	pa(stack, "pa");
}

void	radix_sort(t_stack *stack)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->a_size;
	while ((1 << bit_size) <= size)
		bit_size++;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack->a_size;
		while (size-- && !is_array_sorted(stack->a, stack->a_size))
		{
			if (((stack->a[0] >> j) & 1) == 0)
				pb(stack, "pb");
			else
				rotate(stack->a, "a", stack->a_size);
		}
		while (stack->b_size)
			pa(stack, "pa");
	}
}
