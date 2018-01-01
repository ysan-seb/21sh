/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:41:04 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:41:05 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_strout	*start;
	int			ret;

	start = NULL;
	ret = 0;
	va_start(ap, format);
	start = ft_create_list(format, start);
	start = ft_fill_list(start, ap);
	va_end(ap);
	ret = ft_disp(start);
	return (ret);
}
