/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:43:48 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/22 15:43:50 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_check_resolution_number(char *str, int *i, int *len)
{
	*i = 0;
	*len = 0;
	while (*str)
	{
		while (*str == '0')
			str++;
		while (ft_isdigit(*str))
		{
			if (*len < 6)
			{
				*i *= 10;
				*i += *str - '0';
			}
			*len = *len + 1;
			str++;
			if (!(ft_isdigit(*str)))
			{
				if (*i > 16384)
					*i = 16384;
				return (str);
			}
		}
		str++;
	}
	return (str);
}

void	ft_check_colorstring(char *str)
{
	int			commas;
	int			nums;

	commas = 0;
	nums = 0;
	while (*str)
	{
		if (ft_isdigit(*str) && *str != '0')
		{
			while (ft_isdigit(*str))
			{
				str++;
			}
			nums++;
		}
		if (*str == ',')
			commas++;
		str++;
	}
	if (commas > 2 || nums > 3)
		ft_exit(16);
}

void	ft_arrcln(void **ptr)
{
	void		**ptr_cpy;

	ptr_cpy = ptr;
	while (*ptr)
		free(*ptr++);
	free(ptr_cpy);
}

int		ft_softexit(int nu, t_all *all)
{
	if (nu && all)
		exit(0);
	return (0);
}

void	ft_sortsprites(t_all *all)
{
	t_sprite	tmp;
	int			i;
	int			unsorted;
	int			left;

	unsorted = 1;
	left = all->spritecount - 1;
	while (unsorted)
	{
		unsorted = 0;
		i = 0;
		while (i < left)
		{
			i++;
			if (all->sprites[i - 1].dist < all->sprites[i].dist)
			{
				tmp = all->sprites[i];
				all->sprites[i] = all->sprites[i - 1];
				all->sprites[i - 1] = tmp;
				unsorted = 1;
			}
		}
		left--;
	}
}
