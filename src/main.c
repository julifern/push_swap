/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:24:05 by julifern          #+#    #+#             */
/*   Updated: 2025/04/21 20:14:06 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(t_stack *stack)
{
	if (stack)
		free_all(stack);
	ft_putendl_fd("Error", 2);
	exit (0);
}

void	init(t_stack *stack, char **argv, int argc)
{
	stack->args = get_args(argv + 1);
	if (!stack->args)
		error_msg(NULL);
	if (argc >= 2)
	{
		if (!is_valid(stack->args))
			error_msg(stack);
	}
	init_stacks(stack);
	fill_stack(stack, stack->args);
	if (is_array_sorted(stack->a, stack->a_size))
	{
		free_all(stack);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int i;

	i = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (error_msg(NULL));
	// stack = ft_calloc(1, sizeof(t_stack));
	// if (!stack)
	// 	error_msg(NULL);
	init(&stack, argv, argc);
	index_stack(&stack);
	while (stack.a_size > i)
	{
		ft_printf("%d ", stack.a[i]);
		i++;
	}
	ft_printf("\n");
	if (stack.a_size == 2 && (stack.a[0] > stack.a[1]))
		swap(stack.a, "a", stack.a_size);
	else if (stack.a_size == 3)
		sort_three_size(&stack);
	else if (stack.a_size >= 4 && stack.a_size <= 5)
		sort_four_to_five_size(&stack);
	else
		radix_sort(&stack);
	i = 0;
	while (stack.a_size > i)
	{
		ft_printf("%d ", stack.a[i]);
		i++;
	}
	free_all(&stack);
	return (0);
}
