/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:52:21 by julifern          #+#    #+#             */
/*   Updated: 2025/04/21 13:09:09 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(char **args)
{
	int		i;
	int		j;
	char	*tmp;
	
	i = 0;
	tmp = NULL;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			tmp = args[j];
			if (args[j][0] == '+')
				++tmp;
			if (!ft_strncmp(args[i], tmp, ft_strlen(args[i])))
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

int	is_valid(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!has_digit(args[i]))
			return (0);
		i++;
	}
	if (!is_duplicate(args))
		return (0);
	return (1);
}

char	**get_args(char **array)
{
	int		i;
	char	*str;
	char	**args;

	if (!array)
		return (NULL);
	i = 0;
	str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	while (array[i])
	{
		str = ft_strjoin_free(str, " ", 1, 0);
		str = ft_strjoin_free(str, array[i++], 1, 0);
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}
