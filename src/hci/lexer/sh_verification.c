/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_verification.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:54:19 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:54:20 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_syn_err(char *lexeme)
{
	ft_putstr_fd("Syntax error near unexpected token `", 2);
	ft_putstr_fd(lexeme, 2);
	ft_putstr_fd("\'\n", 2);
	return (SYN_ERR);
}

int			sh_verification(t_token *lex, int ret)
{
	if (!lex)
		return (ret);
	if (lex->category > NEWLINE || lex->category == PIPE)
		return (sh_syn_err(lex->lexeme));
	while (lex->next)
	{
		if (lex->category == REDIRECTION)
		{
			if (lex->next->category != FILDES && lex->next->category != HEREDOC)
				return (sh_syn_err(lex->next->category == NEWLINE ?
							"newline" : lex->next->lexeme));
		}
		if (lex->category >= PIPE)
			if (lex->next->category > NEWLINE || lex->next->category == PIPE)
				return (sh_syn_err(lex->next->lexeme));
		lex = lex->next;
	}
	return (ret);
}
