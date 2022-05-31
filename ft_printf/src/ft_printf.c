/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:59:54 by jhurtado          #+#    #+#             */
/*   Updated: 2022/05/26 13:09:53 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_selection(va_list args, const char select)
{
	int	printed;

	printed = 0;
	if (select == 'c')
		printed += ft_printchar(va_arg(args, int));
	else if (select == 's')
		printed += ft_printstr(va_arg(args, char *));
	else if (select == 'd' || select == 'i')
		printed += ft_printnbr(va_arg(args, int));
	else if (select == 'p')
		printed += ft_printptr(va_arg(args, unsigned long long));
	else if (select == 'u')
		printed += ft_printunsign(va_arg(args, unsigned int));
	else if (select == 'x' || select == 'X')
		printed += ft_printhex(va_arg(args, unsigned int), select);
	else if (select == '%')
	{
		write(1, "%", 1);
		printed += 1;
	}
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		printed;

	printed = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			printed += ft_selection(args, str[i]);
		}
		else
			printed += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
