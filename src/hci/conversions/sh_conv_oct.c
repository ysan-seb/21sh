/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_conv_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:45:26 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:45:27 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	sh_conv_oct(char *str)
{
	char	c;
	size_t	i;

	c = 0;
	i = 0;
	while (i < 2 && (str[i] >= '0' && str[i] < '8'))
		c = c * 8 + str[i++] - '0';
	return (c);
}
