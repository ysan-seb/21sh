/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:54:04 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:54:07 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nb;
	long	pow;

	if (n < 0)
		ft_putchar('-');
	nb = n > 0 ? (long)n : -(long)n;
	pow = 1;
	while (pow * 10 <= nb)
		pow *= 10;
	while (pow > 0)
	{
		ft_putchar((nb - nb / (pow * 10) * pow * 10) / pow + '0');
		pow /= 10;
	}
}
