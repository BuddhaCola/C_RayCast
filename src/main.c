/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:36:31 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/19 21:09:35 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_structinit(t_all *all)
{
	ft_bzero(all, sizeof(t_all));
	if (!(all->mlx.mlx_ptr = mlx_init()))
		ft_exit(6);
	all->mapsize = 1;
	all->mlx.floor = -1;
	all->mlx.ceiling = -1;
}

int			ft_start(int fd, int screenshot)
{
	t_all	all;

	ft_structinit(&all);
	all.screenshot = screenshot;
	ft_readmap(&all, fd);
	all.mlx.img_ptr = mlx_new_image(all.mlx.mlx_ptr, all.mlx.w, all.mlx.h);
	all.mlx.addr = mlx_get_data_addr(all.mlx.img_ptr, &all.mlx.bpp,
	&all.mlx.size_line, &all.mlx.endian);
	ft_rc_mainloop(&all);
	if (screenshot)
		ft_screenshot(&all);
	else
		all.mlx.win_ptr = mlx_new_window(all.mlx.mlx_ptr, all.mlx.w, all.mlx.h,
									"Ladies and gentlemen! cub3D by Wtaylor!");
	mlx_hook(all.mlx.win_ptr, 2, 0L, ft_move, &all);
	mlx_hook(all.mlx.win_ptr, 17, 0L, ft_softexit, &all);
	mlx_put_image_to_window(all.mlx.mlx_ptr, all.mlx.win_ptr,
	all.mlx.img_ptr, 0, 0);
	mlx_loop(all.mlx.mlx_ptr);
	return (0);
}

void		ft_checkextention(char *str)
{
	if (!(str = ft_strrchr(str, '.')))
		return ;
	if (ft_strncmp(str, ".cub", 4) != 0)
		ft_exit(4);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		screenshot;

	screenshot = 0;
	if (argc < 2 || argc > 3)
		ft_exit(1);
	if (((fd = open(argv[1], O_RDONLY)) < 0))
		ft_exit(2);
	ft_checkextention(argv[1]);
	if (argc == 3)
	{
		if (ft_strlen(argv[2]) == 6 && ft_strncmp(argv[2], "--save", 6) == 0)
			screenshot = 1;
		else
			ft_exit(3);
	}
	ft_start(fd, screenshot);
	return (0);
}
