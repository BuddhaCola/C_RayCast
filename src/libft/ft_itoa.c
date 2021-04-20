/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 14:54:49 by wtaylor           #+#    #+#             */
/*   Updated: 2020/11/09 16:45:07 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n)
{
	int				i;
	unsigned int	nu;

	i = 0;
	if (n < 0)
	{
		nu = ((unsigned int)(n * -1));
		i++;
	}
	else
		nu = (unsigned int)n;
	while (nu >= 10)
	{
		nu /= 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	char			*asc;
	int				len;
	unsigned int	nu;

	len = ft_digits(n);
	if (!(asc = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	if (n < 0)
	{
		*asc = '-';
		nu = ((unsigned int)(n * -1));
	}
	else
		nu = (unsigned int)n;
	len--;
	while (nu >= 10)
	{
		*(asc + len) = nu % 10 + '0';
		nu /= 10;
		len--;
	}
	*(asc + len) = nu % 10 + '0';
	return (asc);
}
