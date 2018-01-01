/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_hash_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:39:15 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:39:16 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*sh_hash_get(char *cmd)
{
	t_htable	**htable;
	t_htable	*ctable;

	htable = sh_htable();
	ctable = htable[sh_hash_fct(cmd)];
	while (ctable && !ft_strequ(ctable->cmd, cmd))
		ctable = ctable->next;
	if (ctable)
		return (ctable->path);
	return (NULL);
}
