/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:57:22 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/25 22:57:23 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_raycalc(t_all *all)
{
	all->cam.camerax = 2 * all->cam.x / (double)all->mlx.w - 1;
	all->cam.raydirx = all->cam.dirx + all->cam.cplanex * all->cam.camerax;
	all->cam.raydiry = all->cam.diry + all->cam.cplaney * all->cam.camerax;
	all->cam.mapx = (int)all->cam.posx;
	all->cam.mapy = (int)all->cam.posy;
	all->cam.deltax = fabs(1 / all->cam.raydirx);
	all->cam.deltay = fabs(1 / all->cam.raydiry);
}

void	ft_calculate_sidedist(t_all *all)
{
	if (all->cam.raydirx < 0)
	{
		all->cam.stepx = -1;
		all->cam.sidedistx = (all->cam.posx - all->cam.mapx) * all->cam.deltax;
	}
	else
	{
		all->cam.stepx = 1;
		all->cam.sidedistx = (all->cam.mapx + 1.0 - all->cam.posx) *
																all->cam.deltax;
	}
	if (all->cam.raydiry < 0)
	{
		all->cam.stepy = -1;
		all->cam.sidedisty = (all->cam.posy - all->cam.mapy) *
																all->cam.deltay;
	}
	else
	{
		all->cam.stepy = 1;
		all->cam.sidedisty = (all->cam.mapy + 1.0 - all->cam.posy) *
																all->cam.deltay;
	}
}

void	ft_castray(t_all *all)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		if (all->cam.sidedistx < all->cam.sidedisty)
		{
			all->cam.sidedistx += all->cam.deltax;
			all->cam.mapx += all->cam.stepx;
			all->cam.side = 0;
		}
		else
		{
			all->cam.sidedisty += all->cam.deltay;
			all->cam.mapy += all->cam.stepy;
			all->cam.side = 1;
		}
		if (all->map[all->cam.mapy][all->cam.mapx] == '1')
			hit = 1;
	}
}

void	ft_calculate_lineheight(t_all *all)
{
	if (all->mlx.w > all->mlx.h)
		all->mlx.bigside = all->mlx.w;
	else
		all->mlx.bigside = all->mlx.h;
	if (all->cam.side == 0)
		all->cam.perpwalldist = (all->cam.mapx - all->cam.posx +
								(1.0 - all->cam.stepx) / 2) / all->cam.raydirx;
	else
		all->cam.perpwalldist = (all->cam.mapy - all->cam.posy +
								(1.0 - all->cam.stepy) / 2) / all->cam.raydiry;
	all->cam.lineheight = (int)(all->mlx.w / all->cam.perpwalldist);
	all->cam.drstart = -all->cam.lineheight / 2 + all->mlx.h / 2;
	if (all->cam.drstart < 0)
		all->cam.drstart = 0;
	all->cam.drend = all->cam.lineheight / 2 + all->mlx.h / 2;
	if (all->cam.drend >= all->mlx.h || all->cam.drend < 0)
		all->cam.drend = all->mlx.h - 1;
}
