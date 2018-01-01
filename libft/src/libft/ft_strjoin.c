/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:20:42 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:20:43 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i[3];

	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (s1)
		while (s1[i[1]])
			str[i[0]++] = s1[i[1]++];
	if (s2)
		while (s2[i[2]])
			str[i[0]++] = s2[i[2]++];
	return (str);
}
