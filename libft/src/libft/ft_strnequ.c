/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:22:58 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:22:59 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	while (n && *s1 && *s2)
	{
		if (*s1++ != *s2++)
			return (0);
		n--;
	}
	if (n && *s1 != *s2)
		return (0);
	return (1);
}
