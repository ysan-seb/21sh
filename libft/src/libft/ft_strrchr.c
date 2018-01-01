/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:24:14 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:24:15 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == c)
			return ((char *)(s + i));
	}
	return (NULL);
}
