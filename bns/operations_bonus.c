/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:17:58 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/10 20:18:02 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push(t_stack *org, t_stack *dest)
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
	}
}

void	swap(t_stack *s)
{
	int	tmp;

	if (s->len > 1)
	{
		tmp = s->values[0];
		s->values[0] = s->values[1];
		s->values[1] = tmp;
	}
}

void	rotate(t_stack *s)
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
	}
}

void	reverse_rotate(t_stack *s)
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
	}
}
