/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurtado <jhurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:44:00 by jhurtado          #+#    #+#             */
/*   Updated: 2022/04/26 13:17:10 by jhurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp = (tmp * -1);
		write(fd, "-", 1);
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putchar_fd((tmp % 10) + '0', fd);
	}
	else
		ft_putchar_fd(tmp + '0', fd);
}
