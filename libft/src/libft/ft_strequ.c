/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:19:53 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:19:54 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		diff;

	if (!s1 || !s2)
		return (0);
	diff = 0;
	while (diff == 0 && (*s1 != '\0' || *s2 != '\0'))
		diff = *s1++ - *s2++;
	return (!(diff));
}