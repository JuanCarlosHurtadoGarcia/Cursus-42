/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:02:33 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/16 12:48:11 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	return (first);
}

t_stack	*link_new_node(t_stack *tmp)
{
	t_stack	*tmp2;

	tmp->next = create_new_node();
	tmp2 = tmp;
	tmp = tmp->next;
	return (tmp);
}

void	ft_free_stk(t_stack **stk, int size)
{
	t_stack	*tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	while (size--)
	{
		free(tmp);
		tmp = *stk;
		*stk = (*stk)->next;
	}
}

t_stack	*fill_indexs(t_stack *first, int argc)
{
	int		index;
	int		i;
	int		j;
	t_stack	*ptr;
	t_stack	*ptr2;

	i = 1;
	ptr = first;
	while (i < argc)
	{
		j = 1;
		index = 1;
		ptr2 = ptr;
		while (j < argc - 1)
		{
			ptr2 = ptr2->next;
			if (ptr->number > ptr2->number)
				index++;
			j++;
		}
		ptr->index = index;
		ptr = ptr->next;
		i++;
	}
	return (first);
}

t_stack	*args_in_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	first = create_new_node();
	tmp = first;
	while (i < argc)
	{
		tmp->number = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			tmp = link_new_node(tmp);
		}
		if (i == argc - 1)
		{
			tmp->next = first;
		}
		i++;
	}
	first = fill_indexs(first, argc);
	return (first);
}
