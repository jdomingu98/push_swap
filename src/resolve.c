/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:37:30 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/27 05:40:04 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_values(int *a, int *b, int *k, int exit)
{
	free(k);
	ft_free_stacks(a, b, exit);
}

static void	push_back_to_a(t_stack *a, t_stack *b, t_aux_data *data)
{
	data->cost_a = (int *) malloc(data->len * sizeof(int));
	if (!data->cost_a)
		ft_free_values(a->values, b->values, data->sorted, 1);
	data->cost_b = (int *) malloc(data->len * sizeof(int));
	if (!data->cost_b)
	{
		free(data->cost_a);
		ft_free_values(a->values, b->values, data->sorted, 1);
	}
	data->weights = (int *) malloc(data->len * sizeof(int));
	if (!data->weights)
	{
		ft_free_costs(data->cost_a, data->cost_b);
		ft_free_values(a->values, b->values, data->sorted, 1);
	}
	while (b->len > 0)
	{
		calculate_weights(a, b, data);
		put_on_top_of_b_and_push(a, b, data);
	}
	put_on_first_position(a, data);
	ft_free_costs(data->cost_a, data->cost_b);
	free(data->weights);
}

void	push_to_b(t_stack *a, t_stack *b, t_aux_data *data)
{
	while (a->len > data->len / 2 && a->len > 3)
	{
		if (get_position_in_sorted(a->values[0], *data) <= data->len / 2)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
	while (a->len > 3)
	{
		while (a->values[0] == data->sorted[data->len - 1]
			|| a->values[0] == data->sorted[data->len - 2]
			|| a->values[0] == data->sorted[data->len - 3])
			rotate(a, 'a');
		push(a, b, 'b');
	}
	ft_sort_three(a);
	push_back_to_a(a, b, data);
}
