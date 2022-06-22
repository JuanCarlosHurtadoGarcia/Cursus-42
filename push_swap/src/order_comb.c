/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:32:42 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/22 12:23:55 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	comb_2(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	(void)stack_b;
	tmp = *stack_a;
	if (tmp->index > tmp->next->index)
	{
		ft_switch(*stack_a, 'a');
	}
	return (0);
}

void	comb_3(t_stack **stack_a)
{
	t_stack	*tmp;
	int		middle;
	int		bottom;

	tmp = *stack_a;
	middle = tmp->next->index;
	bottom = tmp->next->next->index;
	if (tmp->index > middle && middle < bottom && bottom > tmp->index)
		ft_switch(tmp, 'a');
	else if (tmp->index > middle && middle > bottom && bottom < tmp->index)
	{
		ft_switch(tmp, 'a');
		ft_rev_rotate(&tmp, 'a');
	}
	else if (tmp->index > middle && middle < bottom && bottom < tmp->index)
		ft_rotate(&tmp, 'a');
	else if (tmp->index < middle && middle > bottom && bottom > tmp->index)
	{
		ft_switch(tmp, 'a');
		ft_rotate(&tmp, 'a');
	}
	else if (tmp->index < middle && middle > bottom & bottom < tmp->index)
		ft_rev_rotate(&tmp, 'a');
	*stack_a = tmp;
}

void	comb_4(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_b;
	i = min_pos(&tmp);
	if (i == 1)
		ft_switch(tmp, 'a');
	else if (i == 2)
	{
		ft_rotate(&tmp, 'a');
		ft_rotate(&tmp, 'a');
	}
	else if (i == 3)
	{
		ft_rev_rotate(&tmp, 'a');
	}
	ft_push(&tmp, &tmp2, 'b');
	comb_3(&tmp);
	ft_push(&tmp2, &tmp, 'a');
	*stack_a = tmp;
	*stack_b = tmp2;
}

void	comb_5(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_b;
	i = max_pos(&tmp);
	while (i > 0)
	{
		ft_rotate(&tmp, 'a');
		i--;
	}
	ft_push(&tmp, &tmp2, 'b');
	comb_4(&tmp, &tmp2);
	ft_push(&tmp2, &tmp, 'a');
	ft_rotate(&tmp, 'a');
	*stack_a = tmp;
}
