/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:48:25 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:48:26 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_ctrl_d(t_line *line, char *save)
{
	if (line->str[line->cur])
		return (sh_del_r(line));
	else if (line->cur == 0 && !save)
		return (EOT);
	return (0);
}
