/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:40:55 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:40:57 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_init(t_tc *init)
{
	if (sh_init_env() < 0)
		return (ft_error("Unable to initialize environment", NULL, NULL));
	if (sh_init_termcaps(init))
		ft_error("Warning", "Line edition can't switch to advanced mode", NULL);
	sh_hash_init();
	return (0);
}
