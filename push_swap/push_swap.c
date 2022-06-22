/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:14:31 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/22 12:46:51 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

int	ft_repeated(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;

	str = " ";
	i = 1;
	j = 0;
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < i)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	**stack2;

	stack2 = malloc(sizeof(t_stack));
	*stack2 = NULL;
	stack1 = args_in_stack(argc, argv);
	//if (!stack1 || argc <= 2 || ft_repeated(argc, argv))
	//	return (0);
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