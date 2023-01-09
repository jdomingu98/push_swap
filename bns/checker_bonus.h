/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:48:21 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/27 16:49:33 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../libft/libft.h"
# include <limits.h>
# include "../gnl/get_next_line_bonus.h"

typedef struct s_stack
{
	int	*values;
	int	len;
}	t_stack;

void	ft_print_error(void);
void	ft_free_stacks(int *a, int *b, int exit);
int		ft_get_true_params_length(int ac, char **av);
void	check_range_and_duplicates(int ac, char **av, t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *s, char choice);
void	ft_execute_moves(t_stack *a, t_stack *b, t_list *instr);
void	ft_free_instr(t_list *instr);
void	push(t_stack *org, t_stack *dest);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	reverse_rotate(t_stack *s);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);
void	swap_both(t_stack *a, t_stack *b);

#endif
