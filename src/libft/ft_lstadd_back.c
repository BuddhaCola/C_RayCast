/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 21:20:46 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/12 19:03:25 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*set;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	set = ft_lstlast(*lst);
	set->next = new;
	new->next = NULL;
}
