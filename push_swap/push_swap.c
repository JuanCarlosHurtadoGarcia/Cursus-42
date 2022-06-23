/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:14:31 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/23 13:51:14 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	**stack2;

	stack2 = malloc(sizeof(t_stack));
	*stack2 = NULL;
	stack1 = args_in_stack(argc, argv);
	if (!ft_check_argv(argv, argc) || !stack1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!ft_check_sort(&stack1, argc) && argc > 2)
	{
		if (argc == 3)
			comb_2(&stack1, stack2);
		if (argc == 4)
			comb_3(&stack1);
		if (argc == 5)
			comb_4(&stack1, stack2);
		if (argc == 6)
			comb_5(&stack1, stack2);
		else
			ft_radix(&stack1, argc - 1);
	}
	return (0);
}

//system("leaks -q push_swap");
/*void	print_list(t_stack *stack)
{
	int		i;
	t_stack	*tmp;
	int		num;

	if (stack == NULL)
	{
		printf("VACIO\n");
		return ;
	}
	i = 1;
	tmp = stack;
	num = tmp->number;
	printf("element0 %i Index %i \n", tmp->number, tmp->index);
	tmp = tmp->next;
	while (i < ft_elements(stack))
	{
		printf("element %i Index %i \n", tmp->number, tmp->index);
		tmp = tmp->next;
		i++;
	}
}*/