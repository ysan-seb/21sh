/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:39:48 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:39:50 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_conversion(t_fields f, va_list ap, int *list_len)
{
	if (f.type == 'd' || f.type == 'i')
		return (ft_int(ap, f));
	else if (f.type == 'u')
		return (ft_unsint(ap, f));
	else if (f.type == 'x')
		return (ft_hexa(ap, f));
	else if (f.type == 'o')
		return (ft_octal(ap, f));
	else if (f.type == 's')
		return (ft_string(ap, f));
	else if (f.type == 'c')
		return (ft_char(ap, f, list_len));
	else if (f.type == 'p')
		return (ft_ptr(ap, f));
	else if (f.type == 'b')
		return (ft_bin(ap, f));
	else if (f.type == '%')
		return (ft_percent(f));
	return (NULL);
}
