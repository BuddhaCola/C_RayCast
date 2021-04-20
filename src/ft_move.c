/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:53:48 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/22 18:53:50 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define MVSPEED 0.2
#define RTSPEED 0.06

void	ft_ws(int keycode, t_all *all)
{
	if (keycode == 13)
	{
		if (all->map[(int)all->cam.posy][(int)(all->cam.posx +
		all->cam.dirx * MVSPEED)] != '1')
			all->cam.posx += all->cam.dirx * MVSPEED;
		if (all->map[(int)(all->cam.posy + all->cam.diry *
		MVSPEED)][(int)all->cam.posx] != '1')
			all->cam.posy += all->cam.diry * MVSPEED;
	}
	if (keycode == 1)
	{
		if (all->map[(int)all->cam.posy][(int)(all->cam.posx -
		all->cam.dirx * MVSPEED)] != '1')
			all->cam.posx -= all->cam.dirx * MVSPEED;
		if (all->map[(int)(all->cam.posy - all->cam.diry *
		MVSPEED)][(int)all->cam.posx] != '1')
			all->cam.posy -= all->cam.diry * MVSPEED;
	}
}

void	ft_ad(int keycode, t_all *all)
{
	if (keycode == 0)
	{
		if (all->map[(int)all->cam.posy][(int)(all->cam.posx -
											all->cam.cplanex * MVSPEED)] != '1')
			all->cam.posx -= all->cam.cplanex * MVSPEED;
		if (all->map[(int)(all->cam.posy - all->cam.cplaney *
										MVSPEED)][(int)all->cam.posx] != '1')
			all->cam.posy -= all->cam.cplaney * MVSPEED;
	}
	if (keycode == 2)
	{
		if (all->map[(int)(all->cam.posy)][(int)(all->cam.posx +
											all->cam.cplanex * MVSPEED)] != '1')
			all->cam.posx += all->cam.cplanex * MVSPEED;
		if (all->map[(int)(all->cam.posy + all->cam.cplaney *
										MVSPEED)][(int)all->cam.posx] != '1')
			all->cam.posy += all->cam.cplaney * MVSPEED;
	}
}

void	ft_turnright(t_all *all)
{
	double olddirx;
	double oldcplane;

	olddirx = all->cam.dirx;
	all->cam.dirx = all->cam.dirx * cos(RTSPEED) - all->cam.diry * sin(RTSPEED);
	all->cam.diry = olddirx * sin(RTSPEED) + all->cam.diry * cos(RTSPEED);
	oldcplane = all->cam.cplanex;
	all->cam.cplanex = all->cam.cplanex * cos(RTSPEED) - all->cam.cplaney *
																sin(RTSPEED);
	all->cam.cplaney = oldcplane * sin(RTSPEED) + all->cam.cplaney *
																cos(RTSPEED);
}

void	ft_turnleft(t_all *all)
{
	double olddirx;
	double oldcplane;

	olddirx = all->cam.dirx;
	all->cam.dirx = all->cam.dirx * cos(-RTSPEED) - all->cam.diry *
																sin(-RTSPEED);
	all->cam.diry = olddirx * sin(-RTSPEED) + all->cam.diry * cos(-RTSPEED);
	oldcplane = all->cam.cplanex;
	all->cam.cplanex = all->cam.cplanex * cos(-RTSPEED) -
										all->cam.cplaney * sin(-RTSPEED);
	all->cam.cplaney = oldcplane * sin(-RTSPEED) + all->cam.cplaney *
															cos(-RTSPEED);
}

int		ft_move(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13 || keycode == 1)
		ft_ws(keycode, all);
	else if (keycode == 0 || keycode == 2)
		ft_ad(keycode, all);
	else if (keycode == 123)
		ft_turnleft(all);
	else if (keycode == 124)
		ft_turnright(all);
	ft_rc_mainloop(all);
	return (0);
}
