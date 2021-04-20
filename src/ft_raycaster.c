/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 00:17:47 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/23 15:41:23 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_putpixels(t_all *all, int texx)
{
	double	texpos;
	double	step;
	int		y;
	int		texy;
	int		color;

	step = 1.0 * all->mlx.tex_hit->height / all->cam.lineheight;
	texpos =
	(int)(all->cam.drstart - all->mlx.h / 2 + all->cam.lineheight / 2) * step;
	y = 0;
	while (y < all->cam.drstart)
		my_mlx_pixel_put(all, all->cam.x, y++, all->mlx.ceiling);
	while (y < all->cam.drend)
	{
		texy = (int)texpos & (all->mlx.tex_hit->height - 1);
		texpos += step;
		color = my_mlx_pixel_get_wall(all, texx, texy);
		my_mlx_pixel_put(all, all->cam.x, y++, color);
	}
	while (y < all->mlx.h)
		my_mlx_pixel_put(all, all->cam.x, y++, all->mlx.floor);
}

void	ft_draw_line(t_all *all)
{
	double	wallx;
	int		texx;

	all->mlx.tex_hit = all->mlx.ea_tex;
	if (all->cam.side == 1)
		all->mlx.tex_hit = all->mlx.no_tex;
	if (all->cam.side == 0 && all->cam.raydirx < 0)
		all->mlx.tex_hit = all->mlx.we_tex;
	if (all->cam.side == 1 && all->cam.raydiry > 0)
		all->mlx.tex_hit = all->mlx.so_tex;
	all->mlx.zbuffer[all->cam.x] = all->cam.perpwalldist;
	if (all->cam.side == 0)
		wallx = all->cam.posy +
				all->cam.perpwalldist * all->cam.raydiry;
	else
		wallx = all->cam.posx +
				all->cam.perpwalldist * all->cam.raydirx;
	wallx -= (int)wallx;
	texx = (int)(wallx * (double)all->mlx.tex_hit->width);
	if (all->cam.side == 0 && all->cam.raydirx < 0)
		texx = all->mlx.tex_hit->width - texx - 1;
	if (all->cam.side == 1 && all->cam.raydiry > 0)
		texx = all->mlx.tex_hit->width - texx - 1;
	ft_putpixels(all, texx);
}

void	ft_drawsprite(t_all *all)
{
	ft_spritedist(all);
	ft_sortsprites(all);
	ft_draw_sprite(all);
}

void	ft_rc_mainloop(t_all *all)
{
	int i;

	all->cam.x = 0;
	mlx_do_sync(all->mlx.mlx_ptr);
	all->mlx.zbuffer = malloc((sizeof(double) * all->mlx.w));
	i = -1;
	while (i++ < all->spritecount)
		all->sprites[i].dist = ((all->cam.posx - all->sprites[i].x) *
						(all->cam.posx - all->sprites[i].x) + (all->cam.posy -
					all->sprites[i].y) * (all->cam.posy - all->sprites[i].y));
	while (all->cam.x < all->mlx.w)
	{
		ft_raycalc(all);
		ft_calculate_sidedist(all);
		ft_castray(all);
		ft_calculate_lineheight(all);
		ft_draw_line(all);
		all->cam.x++;
	}
	ft_drawsprite(all);
	if (all->mlx.win_ptr)
		mlx_put_image_to_window(all->mlx.mlx_ptr,
									all->mlx.win_ptr, all->mlx.img_ptr, 0, 0);
	free(all->mlx.zbuffer);
}
