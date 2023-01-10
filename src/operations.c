/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:19:44 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/25 05:41:12 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *org, t_stack *dest, char dest_name)
{
	int	tmp;
	int	i;

	i = 0;
	if (org->len > 0)
	{
		tmp = org->values[0];
		while (++i < org->len)
			org->values[i - 1] = org->values[i];
		org->len--;
		if (dest->len > 0)
		{
			i = dest->len + 1;
			while (--i > 0)
				dest->values[i] = dest->values[i - 1];
		}
		dest->len++;
		dest->values[0] = tmp;
		if (dest_name == 'a')
			write(STDOUT_FILENO, "pa\n", 3);
		else if (dest_name == 'b')
			write(STDOUT_FILENO, "pb\n", 3);
	}
}

void	swap(t_stack *s, char choice)
{
	if (s->len > 1)
	{
		ft_swap_positions(&s->values[0], &s->values[1]);
		if (choice == 'a')
			write(STDOUT_FILENO, "sa\n", 3);
		else if (choice == 'b')
			write(STDOUT_FILENO, "sb\n", 3);
	}	
}

void	rotate(t_stack *s, char choice)
{
	int	tmp;
	int	i;

	i = 0;
	if (s->len > 1)
	{
		tmp = s->values[0];
		while (++i < s->len)
			s->values[i - 1] = s->values[i];
		s->values[i - 1] = tmp;
		if (choice == 'a')
			write(STDOUT_FILENO, "ra\n", 3);
		else if (choice == 'b')
			write(STDOUT_FILENO, "rb\n", 3);
	}
}

void	reverse_rotate(t_stack *s, char choice)
{
	int	tmp;
	int	i;

	i = s->len;
	if (s->len > 1)
	{
		tmp = s->values[s->len - 1];
		while (--i > 0)
			s->values[i] = s->values[i - 1];
		s->values[i] = tmp;
		if (choice == 'a')
			write(STDOUT_FILENO, "rra\n", 4);
		else if (choice == 'b')
			write(STDOUT_FILENO, "rrb\n", 4);
	}
}
