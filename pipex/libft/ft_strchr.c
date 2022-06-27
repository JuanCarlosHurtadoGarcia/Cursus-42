/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:44:42 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/25 10:33:05 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cad;

	cad = (char *)s;
	while ((unsigned char)*cad != (unsigned char)c && *cad != '\0')
		cad++;
	if ((unsigned char)*cad == (unsigned char)c)
		return (cad);
	else
		return (NULL);
}
