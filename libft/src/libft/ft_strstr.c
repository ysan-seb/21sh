/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:25:13 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:25:15 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i])
	{
		if (!(ft_strncmp(haystack + i, needle, ft_strlen(needle))))
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
