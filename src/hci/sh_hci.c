/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hci.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:56:50 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:56:51 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_hci(t_tc *tc, t_token **lexer, int mret)
{
	t_line	*hist;
	char	*last;
	int		ret;

	if (!(hist = sh_hist_read()))
		return (ft_error(E_SEVER, NULL, NULL));
	ret = 0;
	if (g_signal != SIGINT)
	{
		last = hist->up ? ft_strjoin(hist->up->str, "\n") : NULL;
		ret = sh_edit(hist, last, lexer, tc);
		last ? ft_strdel(&last) : 0;
	}
	sh_hist_del(&hist);
	if (g_signal == SIGINT)
		write(1, "\n", 1);
	if (ret >= 0 && ret & EOT)
		sh_exit(NULL, mret);
	if (ret < 0)
		return (ft_error(E_SEVER, NULL, NULL));
	return (0);
}
