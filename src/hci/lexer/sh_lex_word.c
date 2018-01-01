/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:53:26 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:53:27 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_lex_word(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i] && (quote || !sh_metachar(str[i])))
	{
		if (str[i] == '\\' && str[i + 1])
			i++;
		else
		{
			if (str[i] == quote)
				quote = 0;
			else if ((str[i] == '\"' || str[i] == '\'' || str[i] == '`')
					&& !quote)
				quote = str[i];
		}
		i++;
	}
	return (i);
}
