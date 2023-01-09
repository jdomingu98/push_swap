/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:13:55 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/23 02:40:08 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_free_stacks(int *a, int *b, int exit)
{
	free(a);
	free(b);
	if (exit == 1)
		ft_print_error();
}

void	ft_print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free_instr(t_list *instr)
{
	t_list	*node;

	while (instr)
	{
		node = instr->next;
		free(instr);
		instr = node;
	}
}

int	ft_is_sorted(t_stack *s, char choice)
{
	int	i;

	if (choice == 'a')
	{
		i = 0;
		while (i < (s->len - 1) && s->values[i] < s->values[i + 1])
			i++;
		return (i == s->len - 1);
	}
	else
	{
		i = s->len - 1;
		while (i > 0 && s->values[i] < s->values[i - 1])
			i--;
		return (i == 0);
	}
}
