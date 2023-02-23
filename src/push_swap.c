/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:44:17 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/26 18:57:33 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
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
		if (!ft_is_sorted(&a, 'a'))
			ft_sorting_algoritm(&a, &b);
		free(a.values);
		free(b.values);
	}
	exit(EXIT_SUCCESS);
}
