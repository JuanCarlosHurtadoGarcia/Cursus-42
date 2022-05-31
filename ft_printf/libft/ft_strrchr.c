/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:17:30 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/25 10:50:45 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	pos;

	pos = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + (pos + 1));
	while (pos >= 0)
	{
		if ((unsigned char)s[pos] == (unsigned char)c)
			return ((char *)s + pos);
		pos--;
	}
	return (NULL);
}
