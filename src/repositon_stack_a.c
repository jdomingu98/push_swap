/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repositon_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 22:39:42 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/25 22:39:47 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_lower_number(t_stack *a, t_aux_data data)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = get_position_in_sorted(a->values[0], data);
	while (++i < a->len)
	{
		pos = get_position_in_sorted(a->values[i], data);
		if (pos < min)
			min = pos;
	}
	return (min);
}

void	put_on_first_position(t_stack *a, t_aux_data *data)
{
	int	min;
	int	i;

	min = search_lower_number(a, *data);
	if (get_position_in_sorted(a->values[0], *data) != min)
	{
		i = 0;
		while (a->values[i] != data->sorted[min])
			i++;
		if (i < a->len - i)
		{
			while (--i > -1)
				rotate(a, 'a');
		}
		else
		{
			while (a->len - ++i > -1)
				reverse_rotate(a, 'a');
		}
	}
}
