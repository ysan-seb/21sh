/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cvx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:48:36 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:48:37 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_cut(t_line *line, t_coord **coord, t_tc *tc, char byte)
{
	if (byte == 11 && line->cur != line->used)
	{
		if (tc->cut == 0 && tc->clipboard)
			ft_strclr(tc->clipboard);
		return (sh_cut_k(line, tc));
	}
	else if (byte == 21 && line->cur != 0)
	{
		if (tc->cut == 0 && tc->clipboard)
			ft_strclr(tc->clipboard);
		return (sh_cut_u(line, coord, tc));
	}
	else if (byte == 23)
	{
		if (tc->cut == 0 && tc->clipboard)
			ft_strclr(tc->clipboard);
		return (sh_cut_w(line, coord, tc));
	}
	else
		return (0);
}

int			sh_cvx(t_line *line, t_coord **coord, t_tc *tc, char byte)
{
	int	ret;

	ret = 0;
	if (byte == 11 || byte == 21 || byte == 23)
		ret = sh_cut(line, coord, tc, byte);
	if (byte == 25)
	{
		ret = sh_paste(line, coord, tc);
		tc->cut = 0;
	}
	else
		tc->cut = 1;
	return (ret);
}
