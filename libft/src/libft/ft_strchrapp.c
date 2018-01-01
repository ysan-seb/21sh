/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrapp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:02:36 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:02:37 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrapp(const char *str, const char c)
{
	char	*new;
	int		i;

	if (!str || !(new = ft_strnew(ft_strlen(str) + 1)))
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = c;
	return (new);
}
