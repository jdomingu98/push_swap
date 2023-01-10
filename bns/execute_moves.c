/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:17:46 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/10 20:17:50 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_do_instruction(t_stack *a, t_stack *b, char *instr)
{
	if (ft_strncmp(instr, "pa", 2) == 0)
		push(b, a);
	else if (ft_strncmp(instr, "pb", 2) == 0)
		push(a, b);
	else if (ft_strncmp(instr, "rrr", 3) == 0)
		reverse_rotate_both(a, b);
	else if (ft_strncmp(instr, "rra", 2) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(instr, "rrb", 2) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(instr, "rr", 2) == 0)
		rotate_both(a, b);
	else if (ft_strncmp(instr, "ra", 2) == 0)
		rotate(a);
	else if (ft_strncmp(instr, "rb", 2) == 0)
		rotate(b);
	else if (ft_strncmp(instr, "ss", 2) == 0)
		swap_both(a, b);
	else if (ft_strncmp(instr, "sa", 2) == 0)
		swap(a);
	else if (ft_strncmp(instr, "sb", 2) == 0)
		swap(b);
}

void	ft_execute_moves(t_stack *a, t_stack *b, t_list *instr)
{
	t_list	*node;

	instr = instr->next;
	while (instr)
	{
		ft_do_instruction(a, b, instr->content);
		node = instr;
		instr = instr->next;
		free(node);
	}
}
