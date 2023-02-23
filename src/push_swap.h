/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:51:18 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/27 05:59:05 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	*values;
	int	len;
}	t_stack;

typedef struct s_aux_data
{
	int	*sorted;
	int	len;
	int	*cost_a;
	int	*cost_b;
	int	*weights;
}	t_aux_data;

void	ft_print_error(void);
void	ft_free_stacks(int *a, int *b, int exit);
int		ft_get_true_params_length(int ac, char **av);
void	check_range_and_duplicates(int ac, char **av, t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *s, char choice);
void	ft_sorting_algoritm(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *a);
void	ft_swap_positions(int *a, int *b);
void	push(t_stack *org, t_stack *dest, char dest_name);
void	swap(t_stack *s, char choice);
void	rotate(t_stack *s, char choice);
void	reverse_rotate(t_stack *s, char choice);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);
void	push_to_b(t_stack *a, t_stack *b, t_aux_data *data);
void	ft_free_values(int *a, int *b, int *k, int exit);
void	calculate_weights(t_stack *a, t_stack *b, t_aux_data *data);
int		abs(int nbr);
int		get_position_in_sorted(int nbr, t_aux_data data);
void	put_on_top_of_b_and_push(t_stack *a, t_stack *b, t_aux_data *data);
int		ft_same_sign(int cost_a, int cost_b);
void	ft_free_costs(int *cost_a, int *cost_b);
void	put_on_first_position(t_stack *a, t_aux_data *data);
#endif
