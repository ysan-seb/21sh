/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:51:40 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:51:41 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nblen_base(long long n, int base)
{
	int			len;
	long double	pow;

	pow = 1;
	len = 0;
	if (n < 0)
		len++;
	n < 0 ? n = -n : 0;
	while (n >= (pow *= base))
		len++;
	return (len + 1);
}
