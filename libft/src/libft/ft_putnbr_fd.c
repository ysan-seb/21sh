/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:54:23 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:54:24 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	long	pow;

	if (n < 0)
		ft_putchar_fd('-', fd);
	nb = n > 0 ? (long)n : -(long)n;
	pow = 1;
	while (pow * 10 <= nb)
		pow *= 10;
	while (pow > 0)
	{
		ft_putchar_fd((nb - nb / (pow * 10) * pow * 10) / pow + '0', fd);
		pow /= 10;
	}
}
