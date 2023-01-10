/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_max_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdomingu <jdomingu@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:14:38 by jdomingu          #+#    #+#             */
/*   Updated: 2022/12/22 21:18:14 by jdomingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_if_number(char *str)
{
	int	i;

	i = -1;
	if ((str[0] == '-' && ft_strlen(str) == 1)
		|| (str[0] == '-' && str[1] == '0' && ft_strlen(str) == 2))
		ft_print_error();
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

static int	ft_get_string_length(char *str)
{
	int		i;
	int		j;
	int		len;
	char	**split;

	i = -1;
	len = 0;
	split = ft_split(str, ' ');
	while (split[++i])
	{
		if (ft_check_if_number(split[i]))
			len++;
		else
			ft_print_error();
	}
	i = 0;
	while (split[i])
		i++;
	j = -1;
	while (++j < i)
		free(split[j]);
	free(split);
	return (len);
}

int	ft_get_true_params_length(int ac, char **av)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (++i < ac)
	{
		if (ft_strchr(av[i], ' '))
			len += ft_get_string_length(av[i]);
		else if (ft_check_if_number(av[i]))
		{
			if (av[i][0] == '\0')
				ft_print_error();
			len++;
		}
		else
			ft_print_error();
	}
	return (len);
}
