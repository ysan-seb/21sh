/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:54:04 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:54:05 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_token_del(t_token **begin)
{
	t_token	*tmp;

	if (*begin)
	{
		while (*begin)
		{
			tmp = (*begin)->next;
			ft_strdel(&(*begin)->lexeme);
			free(*begin);
			*begin = NULL;
			*begin = tmp;
		}
	}
	return (-1);
}
