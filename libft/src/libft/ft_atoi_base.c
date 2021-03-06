/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:45:18 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:45:21 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	return (c - 'a' + 10);
}

int			ft_atoi_base(const char *str, int base)
{
	size_t	i;
	int		n;
	int		sign;

	if (!str || base < 2)
		return (0);
	sign = 1;
	i = 0;
	n = 0;
	while (str[i] && str[i] <= ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	str = ft_strlower((char*)str);
	while (str[i] &&
		(ft_isdigit(str[i]) ? str[i] - '0' < base : str[i] - 'a' + 10 < base))
		n = n * base + ft_convert(str[i++]);
	return (n * sign);
}
