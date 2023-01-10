/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:17:17 by jdomingu          #+#    #+#             */
/*   Updated: 2023/01/10 20:17:22 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_check_result(t_stack *a, t_stack *b)
{
	if (ft_is_sorted(a, 'a') && b->len == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

static char	*ft_check_instruction(char *move)
{
	if (ft_strncmp(move, "pa\n", 3) == 0)
		return ("pa");
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		return ("pb");
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		return ("rrr");
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		return ("rra");
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		return ("rrb");
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		return ("rr");
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		return ("ra");
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		return ("rb");
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		return ("ss");
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		return ("sa");
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		return ("sb");
	return ("ff");
}

static void	ft_check_lines(t_stack *a, t_stack *b, t_list *instr)
{
	char	*move;

	instr = ft_calloc(1, sizeof(t_list));
	if (!instr)
		ft_free_stacks(a->values, b->values, 1);
	move = get_next_line(0);
	while (move)
	{
		ft_lstadd_back(&instr, ft_lstnew(ft_check_instruction(move)));
		if (ft_strncmp((ft_lstlast(instr))->content, "ff", 2) == 0)
		{
			if (ft_strncmp(move, "\n", 1) == 0)
				break ;
			ft_free_instr(instr);
			free(move);
			ft_free_stacks(a->values, b->values, 1);
		}
		free(move);
		move = get_next_line(0);
	}
	ft_execute_moves(a, b, instr);
	ft_check_result(a, b);
	free(instr);
	if (move)
		free(move);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_list	instr;
	int		len;

	if (argc > 1)
	{
		len = ft_get_true_params_length(argc, argv);
		a.values = (int *) ft_calloc(len, sizeof(int));
		if (!a.values)
			ft_print_error();
		a.len = 0;
		b.values = (int *) ft_calloc(len, sizeof(int));
		if (!b.values)
		{
			free(a.values);
			ft_print_error();
		}
		b.len = 0;
		check_range_and_duplicates(argc, argv, &a, &b);
		ft_check_lines(&a, &b, &instr);
		ft_free_stacks(a.values, b.values, 0);
	}
	exit(EXIT_SUCCESS);
}
