/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 17:21:13 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/27 17:21:15 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_assign_color(int *orig, int value)
{
	if (*orig >= 0)
		ft_exit(23);
	*orig = value;
}

void	ft_assign_texture(t_tex **tmp, t_tex **orig)
{
	if (*orig)
		ft_exit(21);
	*orig = *tmp;
}

void	ft_toobig(t_all *all, int len_w, int len_h)
{
	int			user_w;
	int			user_h;

	mlx_get_screen_size(all->mlx.mlx_ptr, &user_w, &user_h);
	if ((len_w > 4 || all->mlx.w > user_w) && !all->screenshot)
		all->mlx.w = user_w;
	if ((len_h > 4 || all->mlx.h > user_h) && !all->screenshot)
		all->mlx.h = user_h;
}
