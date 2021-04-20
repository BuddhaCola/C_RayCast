/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:32:09 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/11 23:38:07 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*set;
	t_list	*go;

	set = *lst;
	while (set)
	{
		go = set->next;
		ft_lstdelone(set, del);
		set = go;
	}
	*lst = NULL;
}
