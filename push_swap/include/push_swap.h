/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:14:02 by jhurtado          #+#    #+#             */
/*   Updated: 2022/06/22 12:37:37 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;

}					t_stack;

t_stack				*args_in_stack(int argc, char **argv);
t_stack				*create_new_node(void);
void				ft_free_stk(t_stack **stk, int size);
int					ft_switch(t_stack *stack, int c);
void				ft_push(t_stack **stack_a, t_stack **stack_b, int c);
int					ft_rotate(t_stack **stack, int c);
int					ft_rev_rotate(t_stack **stack, int c);
int					ft_elements(t_stack *stack);
void				ft_end(t_stack **stack_a, int elements);
int					comb_2(t_stack **stack_a, t_stack **stack_b);
void				comb_3(t_stack **stack_a);
void				comb_4(t_stack **stack_a, t_stack **stack_b);
void				comb_5(t_stack **stack_a, t_stack **stack_b);
void				ft_radix(t_stack **a, int max_size);
int					ft_check_sort(t_stack **a, int stack_size);
void				ft_end_plus(t_stack **stack_a, int elements);
int					min_pos(t_stack **stack_a);
int					max_pos(t_stack **stack_a);

#endif
