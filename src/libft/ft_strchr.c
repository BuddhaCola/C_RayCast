/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 20:09:10 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/04 23:22:09 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
