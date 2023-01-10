/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:26:39 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/27 06:00:59 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_min_weight(t_aux_data data, int len)
{
	int	i;
	int	min;

	i = 0;
	min = data.weights[0];
	while (++i < len)
	{
		if (min > data.weights[i])
			min = data.weights[i];
	}
	return (min);
}

static void	rotate_both_s(t_stack *a, t_stack *b, t_aux_data *data, int pos)
{
	int	i;
	int	min;

	if (data->cost_a[pos] <= data->cost_b[pos])
	{
		min = data->cost_a[pos];
		data->cost_a[pos] = 0;
		data->cost_b[pos] -= min;
	}
	else
	{
		min = data->cost_b[pos];
		data->cost_b[pos] = 0;
		data->cost_a[pos] -= min;
	}
	i = -1;
	while (++i < abs(min))
	{
		if (min < 0)
			reverse_rotate_both(a, b);
		else
			rotate_both(a, b);
	}
}

static void	rotate_position(t_stack *s, int cost, char choice)
{
	int	i;	

	i = -1;
	while (++i < abs(cost))
	{
		if (cost < 0)
			reverse_rotate(s, choice);
		else
			rotate(s, choice);
	}
}

void	put_on_top_of_b_and_push(t_stack *a, t_stack *b, t_aux_data *data)
{
	int	i;

	i = -1;
	while (++i < b->len)
	{
		if (data->weights[i] == calculate_min_weight(*data, b->len))
		{
			if (ft_same_sign(data->cost_a[i], data->cost_b[i]))
				rotate_both_s(a, b, data, i);
			rotate_position(b, data->cost_b[i], 'b');
			rotate_position(a, data->cost_a[i], 'a');
			break ;
		}
	}
	push(b, a, 'a');
}
