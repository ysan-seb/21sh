/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:21:21 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:21:24 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	if (!(n))
		return (lens);
	if (lend > n)
		return (n + lens);
	i = lend;
	j = 0;
	while (src[j] && i < n - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (lend + lens);
}
