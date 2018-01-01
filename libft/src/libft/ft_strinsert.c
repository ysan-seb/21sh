/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:20:03 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:20:05 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *body, char *part, size_t pos)
{
	char	*save;
	char	*tmp;

	if (!(save = ft_strdup(body + pos)))
		return (NULL);
	tmp = body;
	body = ft_strnew(ft_strlen(body) + 1);
	body = ft_strcpy(body, tmp);
	free(tmp);
	ft_strclr(body + pos);
	ft_strcat(ft_strcat(body, part), save);
	free(save);
	return (body);
}
