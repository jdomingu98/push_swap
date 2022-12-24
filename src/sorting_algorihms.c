/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorihms.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:17:45 by jdomingu          #+#    #+#             */
/*   Updated: 2022/10/16 00:31:32 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	get_smallest_number_idx(t_stack *s, int start, int *idx)
{
	int	i;
	int	min;

	min = s->stack[start];
	*idx = start;
	i = start;
	while (++i < s->len)
	{
		if (s->stack[i] < min)
		{
			min = s->stack[i];
			*idx = i;
		}
	}	
}

void	set_on_top(t_stack *s, int *i, char choice)
{
	int	prox;

	prox = s->len / 2;
	if (*i == 1)
		swap(s, choice);
	else
	{
		while (*i != 0)
		{
			if (prox >= *i)
			{
				rotate(s, choice);
				*i = (*i - 1) % s->len;
			}
			else
			{
				reverse_rotate(s, choice);
				*i = (*i + 1) % s->len;
			}
		}
	}
}

void	sort_ten_or_less(t_stack *a, t_stack *b)
{
	int	idx;
	int	number_of_push;

	number_of_push = 0;
	while (!ft_sorted(a, 'a'))
	{
		if (a->len == 3 && !ft_sorted(a, 'a'))
			ft_sort_three(a);
		else if (!ft_sorted(a, 'a'))
		{
			get_smallest_number_idx(a, 0, &idx);
			set_on_top(a, &idx, 'a');
			push(a, b, 'b');
			number_of_push++;
		}
	}
	while (number_of_push > 0)
	{
		push(b, a, 'a');
		number_of_push--;
	}
}

static void	copy_elements_and_sort_k(t_stack *a, t_stack *s)
{
	int	i;
	int	j;
	int	aux;

	i = -1;
	while (++i < a->len)
		s->stack[i] = a->stack[i];
	j = 0;
	while (!ft_sorted(s, 'a') && j < s->len)
	{
		get_smallest_number_idx(s, j, &i);
		aux = s->stack[j];
		s->stack[j] = s->stack[i];
		s->stack[i] = aux;
		j++;
	}
}

void	sort_eleven_or_more(t_stack *a, t_stack *b, int nchunks)
{
	t_stack	k;

	if (!ft_sorted(a, 'a'))
	{
		k.len = a->len;
		k.stack = malloc(k.len * sizeof(int));
		if (!k.stack)
		{
			free(a->stack);
			free(b->stack);
			write(STDERR_FILENO, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		copy_elements_and_sort_k(a, &k);
		push_elems_to_b(a, b, k, nchunks);
		if (!ft_sorted(a, 'a'))
			sort_final_chunk(a, b);
		push_back_to_a(a, b);
		free(k.stack);
	}
}
