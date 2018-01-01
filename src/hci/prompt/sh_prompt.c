/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:54:56 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:54:57 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_prompt(int mode)
{
	char	*ps;

	ps = NULL;
	if (mode == 1)
	{
		if (!(ps = getenv("PS1")))
			ps = PS1;
	}
	else if (mode == 2)
	{
		if (!(ps = getenv("PS2")))
			ps = PS2;
	}
	else if (mode == 3)
	{
		if (!(ps = getenv("PS3")))
			ps = PS3;
	}
	else if (mode == 4)
	{
		if (!(ps = getenv("PS4")))
			ps = PS4;
	}
	return (sh_print_prompt(ps));
}
