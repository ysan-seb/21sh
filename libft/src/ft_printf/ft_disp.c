/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:40:04 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:40:07 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_disp(t_strout *s)
{
	int			ret;
	t_strout	*tmp;

	ret = 0;
	while (s)
	{
		write(1, s->str, s->len);
		ret += s->len;
		tmp = s->next;
		free(s->f.flags);
		free(s->str);
		free(s);
		s = tmp;
	}
	return (ret);
}
