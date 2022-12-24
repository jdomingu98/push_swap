/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 03:53:10 by jdomingu          #+#    #+#             */
/*   Updated: 2022/09/28 02:00:24 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	push(t_stack *org, t_stack *dst, char dst_stack)
{
	int	aux;
	int	i;

	i = 0;
	if (org->len > 0)
	{
		aux = org->stack[0];
		while (++i < org->len)
			org->stack[i - 1] = org->stack[i];
		org->len--;
		if (dst->len > 0)
		{
			i = dst->len + 1;
			while (--i > 0)
				dst->stack[i] = dst->stack[i - 1];
		}
		dst->len++;
		dst->stack[0] = aux;
		if (dst_stack == 'a' || dst_stack == 'A')
			write(STDOUT_FILENO, "pa\n", 3);
		else if (dst_stack == 'b' || dst_stack == 'B')
			write(STDOUT_FILENO, "pb\n", 3);
	}	
}

void	swap(t_stack *s, char choice)
{
	int	aux;

	if (s->len > 1)
	{
		aux = s->stack[0];
		s->stack[0] = s->stack[1];
		s->stack[1] = aux;
		if (choice == 'a' || choice == 'A')
			write(STDOUT_FILENO, "sa\n", 3);
		else if (choice == 'b' || choice == 'B')
			write(STDOUT_FILENO, "sb\n", 3);
	}
}

void	rotate(t_stack *s, char choice)
{
	int	aux;
	int	i;

	i = 0;
	if (s->len > 1)
	{
		aux = s->stack[0];
		while (++i < s->len)
			s->stack[i - 1] = s->stack[i];
		s->stack[i - 1] = aux;
		if (choice == 'a' || choice == 'A')
			write(STDOUT_FILENO, "ra\n", 3);
		else if (choice == 'b' || choice == 'B')
			write(STDOUT_FILENO, "rb\n", 3);
	}
}

void	reverse_rotate(t_stack *s, char choice)
{
	int	aux;
	int	i;

	i = s->len;
	if (s->len > 1)
	{
		aux = s->stack[s->len - 1];
		while (--i > 0)
			s->stack[i] = s->stack[i - 1];
		s->stack[i] = aux;
		if (choice == 'a' || choice == 'A')
			write(STDOUT_FILENO, "rra\n", 4);
		else if (choice == 'b' || choice == 'B')
			write(STDOUT_FILENO, "rrb\n", 4);
	}
}
