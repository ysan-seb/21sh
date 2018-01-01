/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:24:30 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:24:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int		i;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = ft_strlen(haystack);
	while (i >= 0)
	{
		if (!(ft_strncmp(haystack + i, needle, ft_strlen(needle))))
			return ((char*)haystack + i);
		i--;
	}
	return (NULL);
}
