/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 00:22:25 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/19 01:08:44 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				ft_bmp_meta(t_all *all, unsigned char *buf)
{
	ft_bzero(buf, 54);
	buf[0] = 'B';
	buf[1] = 'M';
	buf[5] = (all->mlx.w * all->mlx.h * 4 + 54);
	buf[4] = ((all->mlx.w * all->mlx.h * 4 + 54) >> 8);
	buf[3] = ((all->mlx.w * all->mlx.h * 4 + 54) >> 16);
	buf[2] = ((all->mlx.w * all->mlx.h * 4 + 54) >> 24);
	buf[10] = 54;
	buf[14] = 40;
	buf[18] = all->mlx.w;
	buf[19] = all->mlx.w >> 8;
	buf[20] = all->mlx.w >> 16;
	buf[21] = all->mlx.w >> 24;
	buf[22] = -all->mlx.h;
	buf[23] = -all->mlx.h >> 8;
	buf[24] = -all->mlx.h >> 16;
	buf[25] = -all->mlx.h >> 24;
	buf[26] = 1;
	buf[28] = 32;
}

void				ft_bmp_pixels(t_all *all, unsigned char **buf)
{
	int				i;
	int				x;
	int				y;
	int				pxl;

	y = all->mlx.h;
	i = 54;
	while (--y >= 0)
	{
		x = 0;
		while (x < all->mlx.w)
		{
			pxl = *(int *)(all->mlx.addr +
			(y * all->mlx.size_line + x * (all->mlx.bpp / 8)));
			(*buf)[i] = (unsigned char)(pxl);
			(*buf)[i + 1] = (unsigned char)(pxl >> 8);
			(*buf)[i + 2] = (unsigned char)(pxl >> 16);
			(*buf)[i + 3] = (unsigned char)(pxl >> 24);
			i += 4;
			x++;
		}
	}
}

void				ft_screenshot(t_all *all)
{
	unsigned char	buf[54];
	int				fd;
	int				i;
	int				j;

	i = 0;
	if ((fd = open("screenshot.bmp",
				O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
		ft_exit(40);
	ft_bmp_meta(all, buf);
	j = all->mlx.bpp / 8 * all->mlx.w;
	write(fd, &buf, 54);
	while (i < all->mlx.h)
		write(fd, &all->mlx.addr[i++ * all->mlx.size_line], j);
	close(fd);
	write(1, "your screenshot is ready!\n", 26);
	exit(1);
}
