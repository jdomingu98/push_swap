/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:20:50 by jdomingu          #+#    #+#             */
/*   Updated: 2022/11/05 17:27:56 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_inrange(long num)
{
	return (num >= -2147483648 && num <= 2147483647);
}

static int	ft_isduplicate(char **av, int num, int len)
{
	int	i;

	i = 1;
	while (i < len && ft_atoi(av[i]) != num)
		i++;
	return (i < len);
}

static int	check_push_swap(int ac, char **av, int **a, int *b)
{
	int		i;
	size_t	j;
	long	num;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while ((j < ft_strlen(av[i])) && !ft_isalpha(av[i][j]))
			j++;
		if (j < ft_strlen(av[i]))
			return (1);
		num = ft_atoi_ps(av[i], *a, b);
		if (!ft_inrange(num) || ft_isduplicate(av, (int) num, i))
			return (1);
		(*a)[i - 1] = (int) num;
	}
	return (0);
}

void	ft_sort_stack(t_stack *a, t_stack *b)
{
	if (!ft_sorted(a, 'a'))
	{
		if (a->len == 2)
			ft_sort_two(a);
		else if (a->len == 3)
			ft_sort_three(a);
		else if (a->len <= 10)
			sort_ten_or_less(a, b);
		else if (a->len <= 100)
			sort_eleven_or_more(a, b, 5);
		else
			sort_eleven_or_more(a, b, 11);
	}
}

static void ft_error()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void ft_free_and_error(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	ft_error();
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		len;

	if (ac > 1)
	{
		check_params(ac, av, &len);
		a.stack = (int *) malloc(len * sizeof(t_stack));
		b.stack = (int *) malloc(len * sizeof(t_stack));
		if (!a.stack || !b.stack || check_push_swap(ac, av, &a.stack, b.stack))
			ft_free_and_error(&a, &b);
		else
		{
			a.len = len;
			b.len = 0;
			ft_sort_stack(&a, &b);
		}
		free(a.stack);
		free(b.stack);
	}
	exit(EXIT_SUCCESS);
}
