/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:23:30 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:23:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewchr(size_t size, char c)
{
	char	*str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = c;
	return (str);
}
