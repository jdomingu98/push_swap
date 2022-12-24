/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:25:58 by jdomingu          #+#    #+#             */
/*   Updated: 2022/09/28 02:03:51 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Stack top position: 0;
typedef struct s_stack
{
	int	*stack;
	int	len;
}	t_stack;

void	ft_sort_stack(t_stack *a, t_stack *b);
long	ft_atoi_ps(const char *str, int *a, int *b);
int		ft_sorted(t_stack *s, char choice);
void	ft_sort_two(t_stack *s);
void	ft_sort_three(t_stack *s);
void	push(t_stack *org, t_stack *dst, char dst_stack);
void	swap(t_stack *s, char choice);
void	rotate(t_stack *s, char choice);
void	reverse_rotate(t_stack *s, char choice);
void	get_smallest_number_idx(t_stack *a, int start, int *idx);
void	set_on_top(t_stack *a, int *i, char choice);
void	sort_ten_or_less(t_stack *a, t_stack *b);
void	sort_eleven_or_more(t_stack *a, t_stack *b, int nchunks);
void	nearest_element_to_push(t_stack *a, int key_nbr, int *idx);
void	push_elems_to_b(t_stack *a, t_stack *b, t_stack k, int nchks);
void	sort_final_chunk(t_stack *a, t_stack *b);
void	push_back_to_a(t_stack *a, t_stack *b);

#endif
