/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:19:42 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:19:44 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	if (!(new = (char*)malloc(i + 1)))
		return (NULL);
	new[i] = '\0';
	while (i--)
		new[i] = str[i];
	return (new);
}
