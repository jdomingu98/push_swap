/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:09:35 by jdomingu          #+#    #+#             */
/*   Updated: 2023/02/20 21:48:12 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_long(char *str)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while (*str)
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}

static void	ft_check_if_in_range(int *a, int *b, long number)
{
	if (number < INT_MIN || number > INT_MAX)
		ft_free_stacks(a, b, 1);
}

static void	ft_check_for_duplicates(t_stack *a, int *b, int number)
{
	int	i;

	i = -1;
	while (++i < a->len)
	{
		if (a->values[i] == number)
			ft_free_stacks(a->values, b, 1);
	}
}

static void	ft_get_numbers_of_string(t_stack *a, int *b, char *numbers)
{
	int		i;
	int		j;
	char	**split;
	long	parse_to_int;

	i = -1;
	split = ft_split(numbers, ' ');
	while (split[++i])
	{
		parse_to_int = ft_atoi_long(split[i]);
		ft_check_if_in_range(a->values, b, parse_to_int);
		ft_check_for_duplicates(a, b, (int) parse_to_int);
		a->values[a->len] = parse_to_int;
		a->len++;
	}
	i = 0;
	while (split[i])
		i++;
	j = -1;
	while (++j < i)
		free(split[j]);
	free(split);
}

void	check_range_and_duplicates(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;
	long	parse_to_int;

	i = 0;
	while (++i < ac)
	{
		if (ft_strchr(av[i], ' '))
			ft_get_numbers_of_string(a, b->values, av[i]);
		else
		{
			parse_to_int = ft_atoi_long(av[i]);
			ft_check_if_in_range(a->values, b->values, parse_to_int);
			ft_check_for_duplicates(a, b->values, (int) parse_to_int);
			a->values[a->len] = parse_to_int;
			a->len++;
		}
	}
}
