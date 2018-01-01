/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:40:54 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:40:55 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(t_fields f)
{
	char	*ret;
	int		space;
	int		i;

	space = 0;
	if (f.width)
		space = f.width - 1;
	if (!(ret = ft_strnew(space + 1)))
		return (NULL);
	i = 0;
	if (f.flags[2] != '0')
		f.flags[2] = ' ';
	if (f.flags[0] != '-')
	{
		while (space--)
			ret[i++] = f.flags[2];
	}
	ret[i++] = '%';
	while (space-- > 0)
		ret[i++] = ' ';
	return (ret);
}
