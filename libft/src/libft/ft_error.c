/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:45:45 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:45:53 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error(char *m, char *s, char *g)
{
	if (m)
	{
		ft_putstr_fd(m, 2);
		if (s)
		{
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(s, 2);
			if (g)
			{
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(g, 2);
			}
		}
		ft_putstr_fd(".\n", 2);
		return (1);
	}
	return (-1);
}
