/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:29:41 by jdomingu          #+#    #+#             */
/*   Updated: 2022/10/30 22:38:18 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

//Mas que un atoi es un conversor a int, mirar que casos se aceptan y cuales no
long	ft_atoi_ps(const char *str, int *a, int *b)
{
	long	res;
	int		sign;

	(void) a;
	(void) b;
	sign = 1;
	res = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	ft_sorted(t_stack *s, char choice)
{
	int	i;

	if (choice == 'a' || choice == 'A')
	{
		i = 0;
		while (i < (s->len - 1) && s->stack[i] < s->stack[i + 1])
			i++;
		return (i == s->len - 1);
	}
	else if (choice == 'b' || choice == 'B')
	{
		i = s->len - 1;
		while (i > 0 && s->stack[i] < s->stack[i - 1])
			i--;
		return (i == 0);
	}
	return (1);
}

void	ft_sort_two(t_stack *s)
{
	if (s->stack[0] > s->stack[1])
		swap(s, 'a');
}

void	ft_sort_three(t_stack *s)
{
	if (s->stack[2] > s->stack[0] && s->stack[2] > s->stack[1])
		swap(s, 'a');
	else if (s->stack[1] > s->stack[2] && s->stack[1] < s->stack[0])
	{
		swap(s, 'a');
		reverse_rotate(s, 'a');
	}	
	else if (s->stack[0] > s->stack[1] && s->stack[0] > s->stack[2])
		rotate(s, 'a');
	else if (s->stack[0] < s->stack[1] && s->stack[0] < s->stack[2])
	{
		swap(s, 'a');
		rotate(s, 'a');
	}
	else if (s->stack[0] > s->stack[2])
		reverse_rotate(s, 'a');
}

void	nearest_element_to_push(t_stack *a, int key_nbr, int *idx)
{
	int	i;
	int	inormal;
	int	ireverse;

	i = 0;
	while (i <= a->len / 2 && a->stack[i] > key_nbr)
		i++;
	if (a->stack[i] <= key_nbr)
		inormal = i;
	else
		inormal = -1;
	i = a->len - 1;
	while (i > a->len / 2 && a->stack[i] > key_nbr)
		i--;
	if (a->stack[i] <= key_nbr)
		ireverse = i;
	else
		ireverse = -1;
	if (ireverse == -1 && inormal != -1)
		*idx = inormal;
	else if (inormal == -1 && ireverse != -1)
		*idx = ireverse;
	else if (inormal != -1 && ireverse != -1)
	{
		if (a->len - ireverse < inormal)
			*idx = ireverse;
		else
			*idx = inormal;
	}
	else
		*idx = 0; //Mirar que hacer cuando pasa esto
}
