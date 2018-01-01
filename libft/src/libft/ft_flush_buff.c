/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:46:06 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:46:09 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_flush_buff(char *buff, size_t size)
{
	size_t	i;

	write(1, buff, size);
	i = 0;
	while (i < size)
		buff[i++] = '\0';
	return (0);
}