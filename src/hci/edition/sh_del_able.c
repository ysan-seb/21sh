/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_del_able.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:48:46 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:48:47 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			sh_del_able(char *esc, t_line *line)
{
	return (esc[1] == '[' && esc[2] == '3' && esc[3] == '~'
		&& line->cur != line->used);
}