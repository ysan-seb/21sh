/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:50:41 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:50:45 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				diff;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	diff = 0;
	ss1 = (unsigned char*)s1;
	ss2 = (unsigned char*)s2;
	while (diff == 0 && i < n)
	{
		diff = ss1[i] - ss2[i];
		i++;
	}
	return (diff);
}
