/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapvalidation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:13:31 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/22 15:13:44 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_checkplayerpos(t_all *all, int x, int y)
{
	if (all->cam.posx || all->cam.posy)
		ft_exit(30);
	if ((int)ft_strlen(all->map[y - 1]) < x ||
											(int)ft_strlen(all->map[y + 1]) < x)
		ft_exit(41);
}

void	ft_getplayespos(t_all *all, int y, int x, char dir)
{
	ft_checkplayerpos(all, x, y);
	all->cam.posy = y + 0.5;
	all->cam.posx = x + 0.5;
	if (dir == 'N')
	{
		all->cam.diry = -1;
		all->cam.cplanex = .50;
	}
	else if (dir == 'S')
	{
		all->cam.diry = 1;
		all->cam.cplanex = -.50;
	}
	else if (dir == 'E')
	{
		all->cam.dirx = 1;
		all->cam.cplaney = .50;
	}
	else if (dir == 'W')
	{
		all->cam.dirx = -1;
		all->cam.cplaney = -.50;
	}
	all->map[y][x] = '0';
}

void	ft_check_space_neighbor(t_all *all, int y, int x, char **map)
{
	if (!ft_strchr(" 1", map[y][x + 1]))
		ft_exit(39);
	if (x > 0 && !ft_strchr(" 1", map[y][x - 1]))
		ft_exit(39);
	if (y + 1 < all->mapsize && (int)ft_strlen(map[y + 1]) > x + 1 &&
	!ft_strchr(" 1", map[y + 1][x]))
		ft_exit(39);
	if (y > 1 && (int)ft_strlen(map[y - 1]) >= x + 1 &&
	!ft_strchr(" 1", map[y - 1][x]))
		ft_exit(39);
}

void	ft_checkelement(t_all *all, int y, int x, int *spr_i)
{
	if (ft_strchr("NSEW", all->map[y][x]))
		ft_getplayespos(all, y, x, all->map[y][x]);
	if (all->map[y][x] == '2')
	{
		all->sprites[*spr_i].x = x + 0.5;
		all->sprites[*spr_i].y = y + 0.5;
		*spr_i = *(spr_i) + 1;
	}
	if ((y == 0 || y == all->mapsize - 1) && !ft_strchr(" 1", all->map[y][x]))
		ft_exit(35);
	if (x == 0 && !ft_strchr(" 1", all->map[y][x]))
		ft_exit(36);
	if (x == (int)ft_strlen(all->map[y]) - 1 &&
		!ft_strchr(" 1", all->map[y][(int)ft_strlen(all->map[y]) - 1]))
		ft_exit(37);
	if (all->map[y][x] == '0')
	{
		if ((int)ft_strlen(all->map[y - 1]) < x + 1)
			ft_exit(38);
		if ((int)ft_strlen(all->map[y + 1]) < x + 1)
			ft_exit(38);
	}
	if (all->map[y][x] == ' ')
		ft_check_space_neighbor(all, y, x, all->map);
}

void	ft_mapvalidation(t_all *all)
{
	int			y;
	int			x;
	int			spr_i;

	spr_i = 0;
	y = 0;
	while (y < all->mapsize)
	{
		x = 0;
		while (all->map[y][x])
		{
			ft_checkelement(all, y, x, &spr_i);
			x++;
		}
		y++;
	}
	if (!all->cam.posx)
		ft_exit(34);
}
