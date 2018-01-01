/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:23:19 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:23:21 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_space(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
