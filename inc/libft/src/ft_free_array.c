/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:26:33 by julifern          #+#    #+#             */
/*   Updated: 2025/02/07 15:35:53 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void *array, size_t size)
{
	void	**cpy;
	size_t	i;

	i = -1;
	cpy = array;
	while (++i < size)
	{
		if (!cpy[i])
			continue ;
		free(cpy[i]);
	}
	free(cpy);
}
