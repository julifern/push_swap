/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:11:19 by julifern          #+#    #+#             */
/*   Updated: 2025/04/21 20:36:25 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smaller_index(t_stack *stack, int i)
{
	int	smaller;
	int	j;
	
	j = 0;
	smaller = 0;
	while (j < stack->a_size)
	{
		if (stack->a[i] < stack->a[j])
			++smaller;
		j++;
	}
	return (smaller);
}

void	index_stack(t_stack *stack)
{
	int	i;
	int	smaller;
	int	*tmp_a;
	
	tmp_a = ft_calloc(stack->a_size, sizeof(int *));
	if (!tmp_a)
		error_msg(stack);
	i = -1;
	while (++i < stack->a_size)
	{
		smaller = smaller_index(stack, i);
		if (tmp_a[i] < 0)
			tmp_a[i] = -smaller;
		else
			tmp_a[i] = smaller;
	}
	i = stack->a_size;
	while (i--)
		stack->a[i] = tmp_a[i];
	free(tmp_a);
}

void	free_all(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->args)
		ft_free_array(stack->args, stack->a_size);
	if (stack->a)
		free(stack->a);
	if (stack->b)
		free(stack->b);
}