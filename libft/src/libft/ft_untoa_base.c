/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_untoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:27:53 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:27:55 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_untoa_base(unsigned long long nb, int base)
{
	char	*s;
	int		len;

	len = ft_unblen_base(nb, base);
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (nb == 0)
	{
		s[0] = '0';
		s[1] = 0;
		return (s);
	}
	while (nb)
	{
		s[--len] = nb % base > 9 ? nb % base - 10 + 'a' : nb % base + '0';
		nb /= base;
	}
	return (s);
}
