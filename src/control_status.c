/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:13:55 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/23 02:40:08 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stacks(int *a, int *b, int exit)
{
	free(a);
	free(b);
	if (exit == 1)
		ft_print_error();
}

void	ft_print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_is_sorted(t_stack *s, char choice)
{
	int	i;

	if (choice == 'a')
	{
		i = 0;
		while (i < (s->len - 1) && s->values[i] < s->values[i + 1])
			i++;
		return (i == s->len - 1);
	}
	else
	{
		i = s->len - 1;
		while (i > 0 && s->values[i] < s->values[i - 1])
			i--;
		return (i == 0);
	}
}

int	ft_same_sign(int cost_a, int cost_b)
{
	return ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0));
}

void	ft_free_costs(int *cost_a, int *cost_b)
{
	free(cost_a);
	free(cost_b);
}
