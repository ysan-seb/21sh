/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unblen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:27:43 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:27:44 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unblen_base(unsigned long long n, int base)
{
	int			len;
	long double	pow;

	pow = 1;
	len = 0;
	while (n >= (pow *= base))
		len++;
	return (len + 1);
}
