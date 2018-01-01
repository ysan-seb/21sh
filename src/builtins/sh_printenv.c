/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_printenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:34:36 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:34:37 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_printenv(char *env[], char *var)
{
	char	*val;
	int		i;

	if (var)
	{
		if ((val = getenv(var)))
			ft_putendl(val);
		else
			return (1);
	}
	else if (env)
	{
		i = 0;
		while (env[i])
			ft_putendl(env[i++]);
	}
	return (0);
}
