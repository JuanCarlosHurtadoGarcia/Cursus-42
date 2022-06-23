/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:03:15 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/23 10:13:21 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_check_sort(t_stack **a, int stack_size)
{
	t_stack	*is_sort;
	t_stack	*tmp;
	int		i;
	int		sort;
	int		frst;

	i = 1;
	sort = 1;
	is_sort = *a;
	frst = is_sort->number;
	tmp = (*a)->next;
	while (stack_size > i)
	{
		if (((is_sort)->number) > ((tmp)->number))
			sort = 0;
		is_sort = tmp;
		tmp = (tmp)->next;
		i++;
	}
	return (sort);
}

void	ft_stk_mv_radix(t_stack **a, t_stack **b, int max_size, int bit_pos)
{
	int	size;
	int	num;

	size = max_size;
	*b = NULL;
	while (size)
	{
		num = (*a)->index;
		if ((num >> bit_pos) & 1)
			ft_rotate(a, 'a');
		else
			ft_push(a, b, 'b');
		size--;
	}
}

void	ft_radix(t_stack **a, int max_size)
{
	int		bit_pos;
	t_stack	**b;

	bit_pos = 0;
	b = malloc(sizeof(t_stack));
	if (b)
	{
		while (!ft_check_sort(a, max_size))
		{
			ft_stk_mv_radix(a, b, max_size, bit_pos);
			while ((*b))
				ft_push(b, a, 'a');
			bit_pos++;
		}
		free(b);
	}
}
