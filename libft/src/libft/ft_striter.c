/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:20:17 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:20:19 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int		i;

	if (s && f)
	{
		i = 0;
		while (s[i])
			f(s + i++);
	}
}