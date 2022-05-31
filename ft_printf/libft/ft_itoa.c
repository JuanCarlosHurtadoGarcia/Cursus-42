/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:25:43 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/26 11:40:13 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_transform(char *str, int len, int n, int negative)
{
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	tmpn = n;
	len = 0;
	negative = 0;
	if (n < 0)
	{
		n *= -1;
		negative = 1;
	}
	while (tmpn)
	{
		tmpn /= 10;
		len++;
	}
	len += negative;
	str = malloc(sizeof(char) * (len + 1));
	return (ft_transform(str, len, n, negative));
}
