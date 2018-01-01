/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:54:10 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:54:12 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_token_new(t_token **list, char *lexeme, int category)
{
	t_token	*new;
	t_token	*l;

	if (!(new = (t_token*)ft_memalloc(sizeof(t_token))))
		return (-1);
	new->lexeme = lexeme;
	new->category = category;
	new->next = NULL;
	if (*list)
	{
		l = *list;
		while (l->next)
			l = l->next;
		l->next = new;
	}
	else
		*list = new;
	return (0);
}
