/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:42:04 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:42:05 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	sh_cmd_del(t_cmd **cmd)
{
	size_t	i;

	ft_strtabdel((*cmd)->av);
	i = 0;
	while (i < (*cmd)->nb_redir)
	{
		ft_strdel(&((*cmd)->redir[i].type));
		ft_strdel(&((*cmd)->redir[i].right));
		i++;
	}
	ft_memdel((void**)&(*cmd)->redir);
	ft_memdel((void**)cmd);
}
