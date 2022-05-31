/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:45:50 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/21 09:43:12 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *stack, const char *nd, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (nd[j] == '\0')
		return ((char *)stack);
	while (stack[i] != '\0' && i < len)
	{
		while (stack[i + j] == nd[j] && stack[i + j] != '\0' && (i + j < len))
			j++;
		if (nd[j] == '\0')
			return ((char *)stack + i);
		i++;
		j = 0;
	}
	return (NULL);
}
