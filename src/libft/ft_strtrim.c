/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:32:17 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/12 18:46:23 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char str, char const *set)
{
	while (*set)
	{
		if (str == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*p;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1) - 1;
	while (ft_isset(*(s1 + len), set))
	{
		if (len == 0)
		{
			p = ft_calloc(1, sizeof(char));
			return (p);
		}
		len--;
	}
	while (ft_isset(*s1, set))
	{
		s1++;
		len--;
	}
	p = ft_calloc(len + 2, sizeof(char));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, len + 2);
	return (p);
}
