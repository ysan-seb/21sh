/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:25:49 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:25:50 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab_sort(char **tab)
{
	char	*tmp;
	size_t	i;
	int		success;

	if (!tab || !tab[0] || !tab[1])
		return (tab);
	success = 0;
	while (success == 0)
	{
		i = 0;
		success = 1;
		while (tab[i + 1])
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = tmp;
				success = 0;
			}
			i++;
		}
	}
	return (tab);
}
