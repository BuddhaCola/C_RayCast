/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 00:02:50 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/16 19:13:42 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->mlx.addr + (y * all->mlx.size_line + x * (all->mlx.bpp / 8));
	*(unsigned int*)dst = color;
}

int			my_mlx_pixel_get_wall(t_all *all, int x, int y)
{
	char	*dst;
	int		out;

	dst = all->mlx.tex_hit->data_addr + (y * all->mlx.tex_hit->size_line +
											x * (all->mlx.tex_hit->bpp / 8));
	out = *(unsigned int*)dst;
	return (out);
}

int			my_mlx_pixel_get_sprite(t_all *all, int x, int y)
{
	char	*dst;
	int		out;

	dst = all->mlx.sprite->data_addr + (y * all->mlx.sprite->size_line +
												x * (all->mlx.sprite->bpp / 8));
	out = *(unsigned int*)dst;
	return (out);
}

int			create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
