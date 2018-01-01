/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hline_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:51:42 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:51:44 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_line	*sh_hline_new(char *str, t_line *up)
{
	t_line	*new;

	if (!(new = (t_line*)ft_memalloc(sizeof(t_line))))
		return (NULL);
	new->capacity = ((ft_strlen(str) + 1) / BUFF_SIZE + 1) * BUFF_SIZE;
	if (!(new->str = ft_strnew(new->capacity)))
	{
		ft_memdel((void**)new);
		return (NULL);
	}
	ft_strcat(new->str, str);
	new->used = ft_strlen(str);
	new->cur = 0;
	new->up = up;
	new->down = NULL;
	return (new);
}
