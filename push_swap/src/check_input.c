/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:12:26 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/23 11:34:04 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	al(const char *str)
{
	long	rtn;
	int		sign;
	int		cond1;

	cond1 = (*str == '\t' || *str == '\n' || *str == '\v');
	rtn = 0;
	sign = 1;
	while (cond1 || *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		rtn = rtn * 10 + (*str - '0');
		str++;
	}
	if ((rtn * sign) > __LONG_MAX__ || (rtn * sign) < ((__LONG_MAX__ * -1) - 1))
		return (0);
	else
		return ((rtn * sign));
}

int	ft_check_only_int(char **argv, int size)
{
	int	i;
	int	j;

	j = 1;
	while (j < size)
	{
		i = 0;
		if (argv[j][0] == '-')
			i++;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_check_size_int(char **argv, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (al(argv[i]) > __INT_MAX__ || al(argv[i]) < ((__INT_MAX__ * -1) - 1))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_dup_int(char **argv, int size)
{
	int	i;
	int	j;

	j = 1;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_check_argv(char **argv, int size)
{
	if (!ft_check_only_int(argv, size))
		return (0);
	else if (!ft_check_size_int(argv, size))
		return (0);
	else if (!ft_check_dup_int(argv, size))
		return (0);
	return (1);
}
