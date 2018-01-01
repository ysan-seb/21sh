/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:48:07 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:48:08 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	long long	l;
	int			i;

	i = ft_intlen(n);
	if (!(s = ft_strnew(i)))
		return (NULL);
	l = (long long)n;
	if (n < 0)
		s[0] = '-';
	if (!l)
		s[0] = '0';
	while (l)
	{
		s[--i] = ABS(l) % 10 + '0';
		l = l / 10;
	}
	return (s);
}
