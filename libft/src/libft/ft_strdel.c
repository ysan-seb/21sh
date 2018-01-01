/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:19:29 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:19:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	size_t	i;

	if (as)
	{
		i = 0;
		while ((*as)[i])
			(*as)[i++] = '\0';
		free(*as);
		*as = NULL;
	}
}
