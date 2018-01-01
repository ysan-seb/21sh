/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:35:56 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:36:08 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**sh_envdup(char *env[])
{
	char	**new;
	size_t	i;

	if (!env)
		return (NULL);
	i = 0;
	while (env[i])
		i++;
	if (!(new = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (!(new[i] = ft_strdup(env[i])))
		{
			while (i--)
				ft_strdel(&new[i]);
			ft_memdel((void**)&new);
			return (NULL);
		}
		i++;
	}
	return (new);
}
