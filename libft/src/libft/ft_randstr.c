/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:01:19 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:01:21 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_randstr(size_t len)
{
	char	*str;
	size_t	i;

	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = rand();
	return (str);
}
