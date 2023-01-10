/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:13:22 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/26 23:56:17 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	if (a->values[0] > a->values[1] && a->values[0] > a->values[2])
		rotate(a, 'a');
	else if (a->values[1] > a->values[0] && a->values[1] > a->values[2])
		reverse_rotate(a, 'a');
	if (a->values[0] > a->values[1])
		swap(a, 'a');
}

void	ft_swap_positions(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_quicksort(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	i = left;
	j = right;
	pivot = arr[(i + j) / 2];
	while (i <= j)
	{
		while (i < right && arr[i] < pivot)
			i++;
		while (left < j && arr[j] > pivot)
			j--;
		if (i <= j)
		{
			ft_swap_positions(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		ft_quicksort(arr, left, j);
	if (right > i)
		ft_quicksort(arr, i, right);
}

static void	ft_sort_numbers(t_stack *a, t_stack *b)
{
	t_aux_data	data;
	int			i;

	data.sorted = (int *) malloc(a->len * sizeof(int));
	if (!data.sorted)
		ft_free_stacks(a->values, b->values, 1);
	i = -1;
	while (++i < a->len)
		data.sorted[i] = a->values[i];
	data.len = a->len;
	ft_quicksort(data.sorted, 0, data.len - 1);
	push_to_b(a, b, &data);
	free(data.sorted);
}

void	ft_sorting_algoritm(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		swap(a, 'a');
	else if (a->len == 3)
		ft_sort_three(a);
	else
		ft_sort_numbers(a, b);
}
