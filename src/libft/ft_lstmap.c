/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 22:21:03 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/12 19:27:41 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;

	if (!lst)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (newlist == NULL)
		return (NULL);
	if (lst->next)
	{
		newlist->next = ft_lstmap(lst->next, f, del);
		if (!newlist->next)
			ft_lstdelone(newlist, del);
	}
	return (newlist);
}
