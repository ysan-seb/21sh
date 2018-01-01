/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hist_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:51:16 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:51:17 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_hist_del(t_line **hist)
{
	t_line *tmp;

	while (*hist)
	{
		tmp = *hist;
		*hist = (*hist)->up;
		ft_strdel(&tmp->str);
		ft_memdel((void**)&tmp);
	}
}
