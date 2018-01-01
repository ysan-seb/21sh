/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:34:05 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:34:06 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_echo(char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j] == 'n')
			j++;
		if (av[i][j])
			break ;
		i++;
	}
	j = i;
	while (av[i])
	{
		ft_putstr(av[i++]);
		if (av[i])
			ft_putchar(' ');
	}
	if (j == 1)
		ft_putchar('\n');
	return (0);
}
