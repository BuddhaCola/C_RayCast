/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:49:51 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/09 17:31:20 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(p = (char *)ft_calloc(ft_strlen((char *)s) + 1, sizeof(char))))
		return (NULL);
	while (i < ft_strlen((char *)s))
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}
