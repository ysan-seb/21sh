/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redir_restore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:37:34 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:37:35 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			sh_redir_backup(int std[3])
{
	std[0] = dup(0);
	std[1] = dup(1);
	std[2] = dup(2);
	return (0);
}

int			sh_redir_restore(int fd[10], int std[3])
{
	int		i;
	int		ret;

	i = 0;
	while (i < 10)
	{
		if (fd[i] > -1)
			close(fd[i]);
		i++;
	}
	ret = 0;
	if (dup2(std[0], 0) < 0)
		ret = 1;
	if (dup2(std[1], 1) < 0)
		ret = 1;
	if (dup2(std[2], 2) < 0)
		ret = 1;
	return (ret);
}
