/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 14:15:42 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/08 15:57:49 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	s = s + start;
	p = ft_calloc(len + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, s, len + 1);
	return (p);
}
