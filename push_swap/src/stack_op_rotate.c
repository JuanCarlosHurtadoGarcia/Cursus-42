/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:17:50 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/23 11:17:59 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_rotate(t_stack **stack, int c)
{
	t_stack	*tmp;

	tmp = *stack;
	tmp = tmp->next;
	*stack = tmp;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	return (0);
}

void	ft_rotate_r(t_stack **stk1, t_stack **stk2, int c)
{
	ft_rotate(stk1, 0);
	ft_rotate(stk2, 0);
	if (c == 'r')
		ft_putstr_fd("rr\n", 1);
}

int	ft_rev_rotate(t_stack **stack, int c)
{
	t_stack	*tmp;
	t_stack	*back;
	int		num;

	tmp = *stack;
	num = tmp->number;
	back = tmp;
	tmp = tmp->next;
	while (tmp->number != num)
	{
		back = tmp;
		tmp = tmp->next;
	}
	*stack = back;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	return (0);
}

void	ft_reverse_rotate_r(t_stack **stk1, t_stack **stk2, int c)
{
	ft_rev_rotate(stk1, 0);
	ft_rev_rotate(stk2, 0);
	if (c == 'r')
		ft_putstr_fd("rrr\n", 1);
}
