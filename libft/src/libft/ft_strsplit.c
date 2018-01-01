/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:24:41 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:24:43 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_exit(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
	return (NULL);
}

static int	ft_size(const char *str, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
			n++;
		i++;
	}
	return (n + 2);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**new;
	int		i;
	int		j;
	int		l;

	if (!str || !(new = (char**)malloc(sizeof(char*) * ft_size(str, c))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] != c && (i ? str[i - 1] == c : 1) && !(l = 0))
		{
			while (str[i + l] && str[i + l] != c)
				l++;
			if (!(new[j++] = ft_strsub(str, i, l)))
				return (ft_exit(new));
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}
