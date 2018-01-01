/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:01:32 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 12:01:33 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *src, size_t size_src, size_t size_dest,
			size_t elem_size)
{
	void	*dest;

	if (!(dest = ft_memalloc((size_dest) * elem_size)))
		return (NULL);
	if (src)
	{
		ft_memcpy(dest, src, MIN(size_src, size_dest) * elem_size);
		ft_memdel(&src);
	}
	return (dest);
}
