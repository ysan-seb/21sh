/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:38:14 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:38:23 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	sh_norminette(char **lex, size_t i, size_t j, char *quote)
{
	if ((*lex)[i] == *quote)
		*quote = 0;
	else if (((*lex)[i] == '\'' || (*lex)[i] == '\"' || (*lex)[i] == '`')
			&& !*quote)
		*quote = (*lex)[i];
	else
		(*lex)[j++] = (*lex)[i];
	return (j);
}

static char		*sh_rm_quote(char *lex)
{
	size_t	i;
	size_t	j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (lex[i])
	{
		if (lex[i] == '\\' && !quote)
		{
			if (lex[++i] != '\n')
				lex[j++] = lex[i];
		}
		else
			j = sh_norminette(&lex, i, j, &quote);
		i++;
	}
	ft_strclr(lex + j);
	return (lex);
}

t_token			*sh_expansion(t_token *lexer)
{
	t_token	*exp;

	if (lexer)
	{
		exp = lexer;
		while (exp)
		{
			exp->lexeme = sh_exp_tilde(exp->lexeme);
			sh_rm_quote(exp->lexeme);
			exp = exp->next;
		}
	}
	return (lexer);
}
