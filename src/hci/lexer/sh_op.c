/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:53:52 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:53:53 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_ctrl_op(char *str)
{
	if (ft_strnequ(str, ";;&", 3))
		return (3);
	if (ft_strnequ(str, "||", 2) || ft_strnequ(str, "&&", 2)
			|| ft_strnequ(str, ";;", 2) || ft_strnequ(str, ";&", 2)
			|| ft_strnequ(str, "|&", 2))
		return (2);
	if ((str[0] == '&') || str[0] == ';' || str[0] == '|' || str[0] == '('
			|| str[0] == ')' || str[0] == '\n')
		return (1);
	return (0);
}

int		sh_rdir_op(char *str)
{
	if (ft_strnequ(str, "&>>", 3) || ft_strnequ(str, "<<<", 3))
		return (3);
	if (ft_strnequ(str, "&>", 2) || ft_strnequ(str, ">&", 2)
			|| ft_strnequ(str, ">|", 2) || ft_strnequ(str, ">>", 2)
			|| ft_strnequ(str, "<<", 2) || ft_strnequ(str, "<&", 2)
			|| ft_strnequ(str, "<>", 2))
		return (2);
	if (str[0] == '<' || str[0] == '>')
		return (1);
	return (0);
}
