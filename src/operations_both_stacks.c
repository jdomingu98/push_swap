/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:36:17 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/27 00:17:35 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a, 'c');
	rotate(b, 'c');
	write(STDOUT_FILENO, "rr\n", 3);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a, 'c');
	reverse_rotate(b, 'c');
	write(STDOUT_FILENO, "rrr\n", 4);
}
