/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prt_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:55:42 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:55:43 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_prt_shell(char buff[], int *b)
{
	char	*shell;
	int		i;

	shell = SHELL;
	i = 0;
	while (shell[i])
	{
		if (*b == PRT_SIZE)
			*b = ft_flush_buff(buff, PRT_SIZE);
		buff[(*b)++] = shell[i++];
	}
	return (i);
}
