/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 01:11:17 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/19 20:02:42 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_error(int error)
{
	if (error == 1)
		write(2, "wrong number of arguments!\n", 27);
	else if (error == 2)
		write(2, "file opening error!\n", 20);
	else if (error == 3)
		write(2, "wrong arguments!\n", 17);
	else if (error == 4)
		write(2, "second argument extention has to be .cub!\n", 42);
	else if (error == 5)
		write(2, "unable to create bmp file!\n", 27);
	else if (error == 6)
		write(2, "mlx init error!\n", 16);
	if (error == 11)
		write(2, "wrong line in .cub file!\n", 25);
}

void	params_error(int error)
{
	if (error == 12)
		write(2, "forbidden symbol in R/C/F line!\n", 32);
	else if (error == 13)
		write(2, "F/C color error: too many components!\n", 38);
	else if (error == 14)
		write(2, "over 255 number in color component!\n", 36);
	else if (error == 15)
		write(2, "wrong number of color components!\n", 34);
	else if (error == 16)
		write(2, "color component error!\n", 23);
	else if (error == 17)
		write(2, "wrong parameter string!\n", 24);
	else if (error == 18)
		write(2, "mlx_xpm_file_to_image error!\n", 29);
	else if (error == 19)
		write(2, "wrong symbol in R line!\n", 24);
	else if (error == 20)
		write(2, "wrong resolution number!\n", 25);
	else if (error == 21)
		write(2, "re-assigning texture!\n", 22);
	else if (error == 22)
		write(2, "re-assigning resolution!\n", 25);
	else if (error == 23)
		write(2, "re-assigning ceiling/floor color!\n", 34);
}

void	ft_map_error(int error)
{
	if (error == 30)
		write(2, "multiple player position symbol!\n", 25);
	else if (error == 31)
		write(2, "map symbol before all parameters filled!\n", 41);
	else if (error == 32)
		write(2, "map contains forbidden symbol!\n", 31);
	else if (error == 33)
		write(2, "wrong line or content after map!\n", 32);
	else if (error == 34)
		write(2, "no player position symbol found!\n", 33);
	else if (error == 35)
		write(2, "error in first/last str\n", 24);
	else if (error == 36)
		write(2, "error in first column\n", 22);
	else if (error == 37)
		write(2, "error in last column\n", 21);
	else if (error == 38)
		write(2, "no symbol above/under '0' symbol\n", 27);
	else if (error == 39)
		write(2, "wrong symbol near ' '\n", 22);
}

void	ft_screenshot_error(int error)
{
	if (error == 40)
		write(2, "unable to create screenshot file!\n", 35);
	if (error == 41)
		write(2, "player position surrounding error\n", 34);
}

void	ft_exit(int error)
{
	printf("got |%d|\n", error);
	write(2, "Error\n", 6);
	if (error <= 12)
		ft_init_error(error);
	else if (error <= 30)
		params_error(error);
	else if (error < 40)
		ft_map_error(error);
	else if (error <= 50)
		ft_screenshot_error(error);
	exit(1);
}
