/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:49:29 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:49:30 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_hist(t_line **line, t_coord **coord, t_tc tc, t_line *target)
{
	(*line)->cur = sh_move_cur((*line)->cur, 0, *coord, tc);
	target->h_smd = (*line)->h_smd;
	target->h_pos = (*line)->h_pos;
	*line = target;
	(*line)->pos = (*line)->used;
	return (LEXER | DISP);
}
