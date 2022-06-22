/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_switch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 10:43:51 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/22 11:01:57 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_switch(t_stack *stack, int c)
{
	t_stack	*start;
	int		tmp;
	int		tmp_index;

	start = stack;
	if (start && start->next)
	{
		tmp = start->number;
		tmp_index = start->index;
		start->number = start->next->number;
		start->index = start->next->index;
		start->next->number = tmp;
		start->next->index = tmp_index;
	}
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	return (0);
}

void	ft_switch_s(t_stack *swap1, t_stack *swap2, int c)
{
	ft_switch(swap1, 0);
	ft_switch(swap2, 0);
	if (c == 's')
		ft_putstr_fd("ss\n", 1);
}
