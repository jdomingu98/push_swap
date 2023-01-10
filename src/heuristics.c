/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 02:39:17 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/27 05:56:03 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	get_position_in_sorted(int nbr, t_aux_data data)
{
	int	i;
	int	pos;

	i = -1;
	pos = -1;
	while (++i < data.len)
	{
		if (nbr == data.sorted[i])
		{
			pos = i;
			break ;
		}
	}
	return (pos);
}

static int	calculate_cost_a(t_stack *a, t_aux_data data, int nbr)
{
	int	i;
	int	min;
	int	res;
	int	pos;

	min = INT_MAX;
	i = -1;
	res = 0;
	while (++i < a->len)
	{
		pos = get_position_in_sorted(a->values[i], data);
		if (pos > nbr)
		{
			if ((pos - nbr) < min)
			{
				min = pos - nbr;
				res = i;
			}
		}
	}
	if (res <= a->len / 2)
		return (res);
	else
		return (res - a->len);
}

void	calculate_weights(t_stack *a, t_stack *b, t_aux_data *data)
{
	int	i;
	int	pos;

	i = -1;
	while (++i < b->len)
	{	
		pos = get_position_in_sorted(b->values[i], *data);
		if (i <= b->len / 2)
			data->cost_b[i] = i;
		else
			data->cost_b[i] = i - b->len;
		data->cost_a[i] = calculate_cost_a(a, *data, pos);
		data->weights[i] = abs(data->cost_a[i]) + abs(data->cost_b[i]);
	}
}
