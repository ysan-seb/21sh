/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:42:10 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:42:11 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static t_redir	*sh_redir_del(t_redir **redir)
{
	size_t	i;

	i = 0;
	while ((*redir)[i].type || (*redir)[i].right)
	{
		(*redir)[i].type ? ft_strdel(&((*redir)[i].type)) : 0;
		(*redir)[i].right ? ft_strdel(&((*redir)[i].right)) : 0;
		i++;
	}
	ft_memdel((void**)redir);
	return (NULL);
}

static int		sh_redir_left(char *s)
{
	if (ft_strchr(s, '<'))
		return (0);
	if (ft_strchr(s, '>'))
		return (1);
	return (-1);
}

static char		**sh_av_new(t_token *lexer, size_t size)
{
	char	**av;
	size_t	i;

	if (!(av = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (lexer->category != REDIRECTION && lexer->category > FILDES)
		{
			if (!(av[i++] = ft_strdup(lexer->lexeme)))
			{
				ft_strtabdel(av);
				return ((av = NULL));
			}
		}
		lexer = lexer->next;
	}
	return (av);
}

static t_redir	*sh_redir_new(t_token *lexer, size_t size)
{
	t_redir		*new;
	size_t		i;

	if (!(new = (t_redir*)ft_memalloc(sizeof(t_redir) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (lexer->category <= FILDES || lexer->category == REDIRECTION)
		{
			new[i].left = lexer->category == FILDES ? ft_atoi(lexer->lexeme)
				: sh_redir_left(lexer->lexeme);
			lexer->category == FILDES ? (lexer = lexer->next) : 0;
			new[i].type = ft_strdup(lexer->lexeme);
			new[i].right = ft_strdup(lexer->next->lexeme);
			if (!new[i].type || !new[i].right)
				return (sh_redir_del(&new));
			new[i].file = lexer->next->category == FILDES ? 1 : 0;
			lexer = lexer->next;
			i += 1;
		}
		lexer = lexer->next;
	}
	return (new);
}

t_cmd			*sh_cmd_new(t_token *lexer)
{
	t_token	*l;
	t_cmd	*new;
	int		size[2];

	if (!(new = (t_cmd*)ft_memalloc(sizeof(t_cmd))))
		return (NULL);
	ft_bzero(size, sizeof(int) * 2);
	l = lexer;
	while (l->category < PIPE)
	{
		if (l->category == REDIRECTION)
			size[1] += 1;
		else if (l->category > FILDES)
			size[0] += 1;
		l = l->next;
	}
	new->av = sh_av_new(lexer, size[0]);
	new->redir = sh_redir_new(lexer, size[1]);
	new->nb_redir = size[1];
	if (!new->av || !new->redir)
		sh_cmd_del(&new);
	return (new);
}
