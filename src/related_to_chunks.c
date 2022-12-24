/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   related_to_chunks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:31:39 by jdomingu          #+#    #+#             */
/*   Updated: 2022/09/29 02:51:43 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	no_element_greater_in_b(int elem, t_stack *b)
{
	int	i;

	i = -1;
	while (++i < b->len)
	{
		if (b->stack[i] > elem)
			return (0);
	}
	return (1);
}

void	push_elems_to_b(t_stack *a, t_stack *b, t_stack k, int nchks)
{
	int	key_nbr;
	int	i;
	int	count;
	int	idx;

	i = 0;
	while (!ft_sorted(a, 'a') && ++i <= nchks)
	{
		key_nbr = k.stack[i * (k.len / nchks) - 1];
		count = (i - 1) * (k.len / nchks);
		while (++count <= i * (k.len / nchks))
		{
			nearest_element_to_push(a, key_nbr, &idx);
			set_on_top(a, &idx, 'a');
			push(a, b, 'b');
			if (ft_sorted(a, 'a') && no_element_greater_in_b(a->stack[0], b))
				break ;
		}
	}
}

void	sort_final_chunk(t_stack *a, t_stack *b)
{
	if (a->len > 1)
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

static void	get_biggest_number_idx(t_stack *b, int *idx)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = b->stack[0];
	j = 0;
	while (++i < b->len)
	{
		if (b->stack[i] > max)
		{
			j = i;
			max = b->stack[i];
		}
	}
	*idx = j;
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	i;

	while (b->len > 0)
	{
		get_biggest_number_idx(b, &i);
		set_on_top(b, &i, 'b');
		push(b, a, 'a');
	}
}
