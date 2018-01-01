/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_move_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:47:46 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:47:49 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

size_t	sh_move_word_r(t_line *line)
{
	size_t	pos;

	pos = line->cur;
	while (line->str[pos] && !ft_isalnum(line->str[pos]))
		pos += 1;
	while (ft_isalnum(line->str[pos]))
		pos += 1;
	return (pos);
}

size_t	sh_move_word_l(t_line *line)
{
	size_t		pos;

	pos = line->cur - 1;
	while ((pos + 1) > 0 && line->str[pos] && !ft_isalnum(line->str[pos]))
		pos -= 1;
	while ((pos + 1) > 0 && ft_isalnum(line->str[pos]))
		pos -= 1;
	return (pos + 1);
}
