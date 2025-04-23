/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julifern <julifern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:52:21 by julifern          #+#    #+#             */
/*   Updated: 2025/04/23 17:04:13 by julifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_overflow(char *str)
{
	long	val;

	val = ft_atol(str);
	if (val > INT_MAX || val < INT_MIN)
		return (1);
	return (0);
}

int	has_digit(char *str)
{
	int	i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[i + 1] != 0)
		++i;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
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
		if (has_overflow(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32)
			return (0);
		++i;
	}
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
		if ((ft_strlen(array[i]) <= 1 && array[i][0] == ' ') ||
			is_only_spaces(array[i]) || !array[i])
		{
			free(str);
			error_msg(NULL);
		}
		str = ft_strjoin_free(str, " ", 1, 0);
		str = ft_strjoin_free(str, array[i++], 1, 0);
	}
	args = ft_split(str, ' ');
	free(str);
	return (args);
}
