/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:18:30 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/10 22:21:25 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int n)
{
	if (*s != '\0' && *s != (char)n)
		while (*++s)
		{
			if (*s == (char)n)
				return ((char *)s);
		}
	if (*s == (char)n)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	len = (ft_strlen(s) + 1);
	dup = ft_calloc(len, sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcat(dup, s, len);
	return (dup);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	const char	*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = dsize;
	while (n-- && *dst)
		dst++;
	dlen = dst - d;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src)
	{
		if (n)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - s));
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (*s++)
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*p;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = ft_calloc(len, sizeof(char));
	if (p == NULL)
		return (NULL);
	ft_strlcat(p, s1, len);
	ft_strlcat(p, s2, len + 1);
	return (p);
}
