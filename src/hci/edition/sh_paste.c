/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_paste.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:49:52 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:49:55 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_paste(t_line *line, t_coord **coord, t_tc *tc)
{
	size_t	len;

	if (!tc->clipboard)
		return (0);
	len = ft_strlen(tc->clipboard);
	if (line->used + ft_strlen(tc->clipboard) >= line->capacity)
	{
		line->capacity += BUFF_SIZE * ((len / BUFF_SIZE) + 1);
		if (!(line->str = ft_realloc(line->str, line->used,
						line->capacity, sizeof(char))))
			return (-1);
	}
	ft_memmove(line->str + line->cur + len, line->str + line->cur,
			ft_strlen(line->str + line->cur));
	ft_strncpy(line->str + line->cur, tc->clipboard, len);
	line->used += len;
	free(*coord);
	if (!(*coord = sh_create_coord(line, tc->prompt)))
		return (-1);
	line->pos = line->cur + ft_strlen(tc->clipboard);
	return (DISP | LEXER);
}
