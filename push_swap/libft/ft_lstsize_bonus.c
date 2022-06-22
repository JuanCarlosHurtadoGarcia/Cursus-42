/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:30:51 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/27 12:39:44 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	if (temp)
	{
		i++;
		while (temp->next)
		{
			i++;
			temp = temp->next;
		}
	}
	return (i);
}
