/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:44:23 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/22 10:19:07 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_stack	*ft_new_copied_node(t_stack *to_copy_node)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = to_copy_node->number;
	new_node->index = to_copy_node->index;
	new_node->next = to_copy_node->next;
	return (new_node);
}

void	ft_push_b_void(t_stack **a, t_stack **b)
{
	t_stack	*memo_2;

	memo_2 = NULL;
	*b = ft_new_copied_node(*a);
	memo_2 = *a;
	ft_end(a, ft_elements(*a));
	free(memo_2);
	(*b)->next = *b;
}

void	ft_push_b_filled(t_stack **a, t_stack **b)
{
	t_stack	*tmpn;
	int		num;

	tmpn = NULL;
	tmpn = ft_new_copied_node(*a);
	tmpn->next = *b;
	num = ft_elements(*b);
	*b = tmpn;
	ft_end_plus(b, num);
	tmpn = *a;
	ft_end(a, ft_elements(*a));
	if ((*a)->number == (*b)->number)
		*a = NULL;
	free(tmpn);
}

void	ft_push(t_stack **a, t_stack **b, int c)
{
	if (!(*b) && *a)
		ft_push_b_void(a, b);
	else if (*a)
		ft_push_b_filled(a, b);
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}
