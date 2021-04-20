/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:07:18 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/04 23:37:54 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int n)
{
	int i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)n)
			return ((char *)s + i);
	}
	return (0);
}
