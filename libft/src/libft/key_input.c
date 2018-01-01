/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:28:09 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:28:10 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	key_input(void)
{
	char	buff[6];
	long	ret;
	int		i;

	ret = 0;
	i = 6;
	ft_memset(buff, 0, 6);
	read(0, buff, 6);
	while (i--)
		ret += ret * 256 + buff[i];
	return (ret);
}
