/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:21:09 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:21:11 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinf(char *s1, char const *s2)
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
	if (s1)
		ft_strdel(&s1);
	return (str);
}
