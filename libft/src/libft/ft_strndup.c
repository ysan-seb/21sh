/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:22:47 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:22:49 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	if (!(str = ft_strnew(MIN(n, ft_strlen(s)))))
		return (NULL);
	return (ft_strncpy(str, s, MIN(n, ft_strlen(s))));
}
