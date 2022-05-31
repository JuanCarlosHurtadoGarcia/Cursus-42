/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:16:25 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/21 10:28:48 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*store;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	store = malloc(sizeof(char) * size + 1);
	if (!store)
		return (NULL);
	while (s1[i])
	{
		store[i] = s1[i];
		i++;
	}
	store[size] = '\0';
	return (store);
}
