/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:46:44 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:46:45 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_inttabnew(size_t size)
{
	int		*tab;
	size_t	i;

	if (!(tab = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		tab[i++] = 0;
	return (tab);
}
