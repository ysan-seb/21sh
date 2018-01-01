/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 11:49:34 by ysan-seb          #+#    #+#             */
/*   Updated: 2017/11/05 11:49:35 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*previous;
	t_list	*begin;
	void	*content;
	size_t	size;

	begin = NULL;
	while (lst)
	{
		content = (f(lst))->content;
		size = (f(lst))->content_size;
		if (!(new = ft_lstnew(content, size)))
			return (NULL);
		if (!(begin))
		{
			if (!(begin = ft_lstnew(content, size)))
				return (NULL);
			new = begin;
			previous = new;
		}
		previous->next = new;
		previous = new;
		lst = lst->next;
	}
	return (begin);
}
