/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:51:57 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/19 20:01:52 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_checkforbiddensymbols(char *str, char *allowed)
{
	while (*str)
	{
		if (ft_strchr(allowed, *str))
			str++;
		else
			return (0 - *str);
	}
	return (0);
}

void	ft_getbgcolor(char *str, t_all *all, int side)
{
	int			color;
	char		**rgb_char;
	int			i;
	int			rgb_int[3];

	i = 0;
	if (ft_checkforbiddensymbols(++str, ", 0123456789") < 0)
		ft_exit(12);
	ft_check_colorstring(str);
	rgb_char = ft_split(str, ',');
	rgb_char[3] = 0;
	while (rgb_char[i])
	{
		if ((rgb_int[i] = ft_atoi(rgb_char[i])) < 0 || rgb_int[i++] > 255)
			ft_exit(14);
	}
	if (i != 3)
		ft_exit(15);
	color = create_trgb(0, rgb_int[0], rgb_int[1], rgb_int[2]);
	if (side == 'C')
		ft_assign_color(&all->mlx.ceiling, color);
	else
		ft_assign_color(&all->mlx.floor, color);
	ft_arrcln((void **)rgb_char);
}

void	ft_gettexture(char *str, t_all *all)
{
	t_tex		*ptr;

	ptr = malloc(sizeof(t_tex));
	if (ft_strncmp("EA ", str, 3) == 0)
		ft_assign_texture(&ptr, &all->mlx.ea_tex);
	else if (ft_strncmp("WE ", str, 3) == 0)
		ft_assign_texture(&ptr, &all->mlx.we_tex);
	else if (ft_strncmp("NO ", str, 3) == 0)
		ft_assign_texture(&ptr, &all->mlx.no_tex);
	else if (ft_strncmp("SO", str, 2) == 0)
		ft_assign_texture(&ptr, &all->mlx.so_tex);
	else if (ft_strncmp("S ", str, 2) == 0)
		ft_assign_texture(&ptr, &all->mlx.sprite);
	else
		ft_exit(17);
	*str + 1 != ' ' ? str += 2 : str++;
	str = ft_strtrim(str, " ");
	if (!(ptr->img_ptr = mlx_xpm_file_to_image(all->mlx.mlx_ptr,
							str, &ptr->width, &ptr->height)))
		ft_exit(18);
	ptr->data_addr = mlx_get_data_addr(ptr->img_ptr, &ptr->bpp, &ptr->size_line,
																&ptr->endian);
	free(str);
}

void	ft_getresolution(char *str, t_all *all)
{
	int			i;
	int			len_w;
	int			len_h;

	i = 0;
	if (ft_checkforbiddensymbols(++str, " 0123456789") < 0)
		ft_exit(12);
	while (*str++)
	{
		if (ft_isdigit(*str))
		{
			if (!(all->mlx.w))
				str = ft_check_resolution_number(str, &all->mlx.w, &len_w);
			else
				str = ft_check_resolution_number(str, &all->mlx.h, &len_h);
			i++;
		}
		if ((*str != ' ' && *str != '\0' && !(ft_isdigit(*str))))
			ft_exit(19);
	}
	if (i != 2)
		ft_exit(20);
	ft_toobig(all, len_w, len_h);
}
