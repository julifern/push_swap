/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:26:50 by julifern          #+#    #+#             */
/*   Updated: 2025/04/21 19:59:51 by julifern         ###   ########.fr       */
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
	while (stack->b_size <= 1) //tant qu'on a pas mis 1 element dans la stack
	{
		if (stack->a[0] == 0 || stack->a[0] == 1) 
			pb(stack, "pb"); // si notre premier element est soit 1 ou 2, ou le push
		else
			rotate(stack->a, "a", stack->a_size);// sinon on rotate pour tomber dessus
	} //stack b contient 1 et 2
	if (stack->b[0] == 0) // si le premier element de b est 1
		swap(stack->b, "sb", stack->b_size); //alors on swap pour preparer au push
	if (stack->a[2] != 4) // si le 3eme element de a est different de 5
	{
		if (stack->a[0] == 4) // si le premier est 5
			rotate(stack->a, "a", stack->a_size); // on rotate : ex de (5, 4, 3) a (4, 3, 5)
		else
			reverse(stack->a, "a", stack->a_size); // inverse sinon
	}
	if (stack->a[0] > stack->a[1]) // si les deux premieres elements sont inverse
		swap(stack->a, "sa", stack->a_size); // on les swap
	pa(stack, "pa");
	pa(stack, "pa");
}

void	radix_sort_b(t_stack *stack, int b_size, int bit_size, int j)
{
	while (b_size && j <= bit_size && !is_array_sorted(stack->b, stack->b_size))
	{
		if (((stack->b[0] >> j) & 1) == 0)
			rotate(stack->b, "b", stack->b_size);
		else
			pa(stack, "pa");
		--b_size;
	}
	if (is_array_sorted(stack->b, stack->b_size))
	{
		while (stack->b_size)
			pa(stack, "pa");
	}
}

void	radix_sort(t_stack *stack)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
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
		radix_sort_b(stack, stack->b_size, bit_size, j + 1);
	}
	while (stack->b_size)
		pa(stack, "pa");
}