/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:56:13 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/09 20:59:19 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_howmany(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			i++;
		s++;
	}
	return (i);
}

static char	**ft_free(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	int		wrdlen;
	int		newwrd;

	newwrd = 0;
	if (!s)
		return (NULL);
	if (!(arr = (char **)ft_calloc((ft_howmany(s, c) + 1), sizeof(char *))))
		return (NULL);
	while (*s)
	{
		wrdlen = 0;
		while (*s == c && *(s))
			s++;
		while (*s != c && *s)
		{
			wrdlen++;
			s++;
		}
		if (wrdlen)
			if (!(arr[newwrd] = ft_substr(s - wrdlen, 0, wrdlen)))
				return (ft_free(arr));
		newwrd++;
	}
	return (arr);
}
