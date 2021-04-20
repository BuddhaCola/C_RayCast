/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:17:02 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/25 19:17:04 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_spritedist(t_all *all)
{
	int		i;

	i = 0;
	while (i < all->spritecount)
	{
		all->sprites[i].dist = ((all->cam.posx - all->sprites[i].x)
						* (all->cam.posx - all->sprites[i].x) + (all->cam.posy -
					all->sprites[i].y) * (all->cam.posy - all->sprites[i].y));
		if (all->sprites[i].dist < 0.4)
			all->sprites[i].invisible = 1;
		else
			all->sprites[i].invisible = 0;
		i++;
	}
}

void	ft_transformsprite(t_all *all, int i)
{
	double spritex;
	double spritey;
	double invdet;
	double transformx;

	spritex = all->sprites[i].x - all->cam.posx;
	spritey = all->sprites[i].y - all->cam.posy;
	invdet = 1.0 / (all->cam.cplanex * all->cam.diry - all->cam.dirx *
															all->cam.cplaney);
	transformx = invdet * (all->cam.diry * spritex - all->cam.dirx *
																	spritey);
	all->sprites->transformy = invdet * (-all->cam.cplaney * spritex +
													all->cam.cplanex * spritey);
	all->sprites->spritescreenx = (int)((all->mlx.w / 2.0) * (1 + transformx /
													all->sprites->transformy));
}

void	ft_width_height(t_all *all)
{
	all->sprites->spriteheight = abs((int)(all->mlx.w /
												(all->sprites->transformy)));
	all->sprites->drawstarty = -all->sprites->spriteheight / 2 + all->mlx.h / 2;
	if (all->sprites->drawstarty < 0)
		all->sprites->drawstarty = 0;
	all->sprites->drawendy = all->sprites->spriteheight / 2 + all->mlx.h / 2;
	if (all->sprites->drawendy >= all->mlx.h)
		all->sprites->drawendy = all->mlx.h - 1;
	all->sprites->spritewidth = abs((int)(all->mlx.w /
												(all->sprites->transformy)));
	all->sprites->drawstartx = -all->sprites->spritewidth / 2 +
								all->sprites->spritescreenx;
	if (all->sprites->drawstartx < 0)
		all->sprites->drawstartx = 0;
	all->sprites->drawendx = all->sprites->spritewidth / 2 +
													all->sprites->spritescreenx;
	if (all->sprites->drawendx >= all->mlx.w)
		all->sprites->drawendx = all->mlx.w - 1;
}

void	ft_sprite_fillcolumn(t_all *all, int stripe)
{
	int		color;
	int		d;
	int		y;
	int		texx;
	int		texy;

	texx = (int)(256 * (stripe - (-all->sprites->spritewidth / 2 +
				all->sprites->spritescreenx)) * all->mlx.sprite->width /
											all->sprites->spritewidth) / 256;
	y = all->sprites->drawstarty;
	while (y < all->sprites->drawendy)
	{
		d = (y) * 256 - all->mlx.h * 128 +
			all->sprites->spriteheight * 128;
		texy = ((d * all->mlx.sprite->height) /
				all->sprites->spriteheight) / 256;
		color = my_mlx_pixel_get_sprite(all, texx, texy);
		if (color != 0x0)
			my_mlx_pixel_put(all, stripe, y, color);
		y++;
	}
}

void	ft_draw_sprite(t_all *all)
{
	int		stripe;
	int		i;

	i = 0;
	while (i < all->spritecount)
	{
		if (!all->sprites[i].invisible)
		{
			ft_transformsprite(all, i);
			ft_width_height(all);
			stripe = all->sprites->drawstartx;
			while (stripe < all->sprites->drawendx)
			{
				if (all->sprites->transformy > 0 && stripe > 0 &&
					stripe < all->mlx.w &&
					all->sprites->transformy < all->mlx.zbuffer[stripe])
					ft_sprite_fillcolumn(all, stripe);
				stripe++;
			}
		}
		i++;
	}
}
