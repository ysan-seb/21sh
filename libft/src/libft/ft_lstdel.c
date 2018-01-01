/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:49:04 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:49:06 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;
	t_list	*tmp;

	l = *alst;
	while (l)
	{
		tmp = l;
		del(l->content, l->content_size);
		l = tmp->next;
		free(tmp);
	}
	*alst = NULL;
}
