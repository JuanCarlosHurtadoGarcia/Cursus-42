/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:21:17 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/22 09:14:57 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	ft_elements(t_stack *stack)
{
	t_stack	*tmp;
	int		num;
	int		i;

	i = 1;
	tmp = stack;
	num = tmp->number;
	tmp = tmp->next;
	while (tmp->number != num)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	min_pos(t_stack **stack_a)
{
	t_stack	*tmp;
	int		minimum_pos;
	int		i;
	int		num;

	tmp = *stack_a;
	minimum_pos = 0;
	i = 0;
	num = tmp->index;
	tmp = tmp->next;
	while (tmp->index != num)
	{
		i++;
		if (tmp->index < num)
		{
			minimum_pos = i;
			num = tmp->index;
		}
		tmp = tmp->next;
	}
	return (minimum_pos);
}

int	max_pos(t_stack **stack_a)
{
	t_stack	*tmp;
	int		max_pos;
	int		i;
	int		num;

	tmp = *stack_a;
	max_pos = 0;
	i = 0;
	num = tmp->index;
	tmp = tmp->next;
	while (tmp->index != num)
	{
		i++;
		if (tmp->index > num)
		{
			max_pos = i;
			num = tmp->index;
		}
		tmp = tmp->next;
	}
	return (max_pos);
}

void	ft_end(t_stack **stack_a, int elements)
{
	t_stack	*tmp;
	t_stack	*prev;
	int		i;

	i = 0;
	tmp = *stack_a;
	prev = tmp;
	while (i < elements)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	prev->next = tmp->next;
	*stack_a = tmp->next;
}

void	ft_end_plus(t_stack **stack_a, int elements)
{
	t_stack	*tmp;
	t_stack	*prev;
	int		i;

	i = 0;
	tmp = *stack_a;
	prev = tmp;
	while (i < elements)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	tmp->next = *stack_a;
}
