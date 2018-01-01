/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:23:44 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:23:45 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	len;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	len = ft_strlen(needle);
	while (haystack[i] && i < n && len <= n - i)
	{
		if (!(ft_strncmp(haystack + i, needle, len)))
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
