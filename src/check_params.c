/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 16:41:20 by jdomingu          #+#    #+#             */
/*   Updated: 2022/11/05 17:27:10 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_there_is_space(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (str[i] == ' ');
}

static int	ft_is_number(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' && ft_strlen(str) == 1)
		return (0);
	else if (str[0] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	return (str[i] == '\0');
}

static int  ft_check_if_number(char *num, int *len)
{
    if (ft_is_number(num))
		(*len)++;
	else
		ft_error();
}

//Checks if are positive or negative numbers and detect "" params
void    check_params(int ac, char **av, int *len)
{
	int		i;
	int		j;
	char	**num;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (ft_there_is_space(av[i]))
		{
			num = ft_split(av[i], ' ');
			while (num[j] != 0)
			{
                ft_check_if_number(num[j], len);
				j++;
			}
			if (*len == 0)
				ft_error();
		}
		else
            ft_check_if_number(av[i], len);
	}
}