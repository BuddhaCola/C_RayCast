/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 20:43:56 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/24 15:21:49 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>

# include <stdio.h>

typedef	struct	s_sprite
{
	double		x;
	double		y;
	double		dist;
	double		transformy;
	int			spriteheight;
	int			drawstartx;
	int			drawstarty;
	int			drawendx;
	int			drawendy;
	int			spritescreenx;
	int			spritewidth;
	int			invisible;
}				t_sprite;

typedef	struct	s_tex
{
	void		*img_ptr;
	int			width;
	int			height;
	void		*data_addr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_tex;

typedef struct	s_mlx {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*addr;
	int			bpp;
	int			size_line;
	int			endian;
	int			w;
	int			h;
	int			bigside;
	double		*zbuffer;
	t_tex		*sprite;
	t_tex		*no_tex;
	t_tex		*ea_tex;
	t_tex		*we_tex;
	t_tex		*so_tex;
	t_tex		*tex_hit;
	int			ceiling;
	int			floor;
}				t_mlx;

typedef	struct	s_cam
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		cplanex;
	double		cplaney;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		deltax;
	double		deltay;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	int			side;
	int			x;
	double		perpwalldist;
	int			drstart;
	int			drend;
	int			lineheight;
}				t_cam;

typedef	struct	s_all {
	t_mlx		mlx;
	t_cam		cam;
	char		**map;
	int			mapsize;
	size_t		mapwidth;
	int			spritecount;
	t_sprite	*sprites;
	int			screenshot;
}				t_all;

int				ft_readmap(t_all *all, int fd);
char			*ft_check_resolution_number(char *str, int *i, int *len);
void			ft_getresolution(char *str, t_all *all);
void			ft_gettexture(char *str, t_all *all);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
int				my_mlx_pixel_get_sprite(t_all *all, int x, int y);
int				create_trgb(int t, int r, int g, int b);
void			ft_getbgcolor(char *str, t_all *all, int side);
int				ft_checkforbiddensymbols(char *str, char *allowed);
void			ft_screenshot(t_all *all);
void			ft_exit(int	error);
void			ft_rc_mainloop(t_all *all);
void			ft_mapvalidation(t_all *all);
void			ft_check_colorstring(char *str);
void			ft_arrcln(void **ptr);
int				ft_move(int keycode, t_all *all);
int				my_mlx_pixel_get_wall(t_all *all, int x, int y);
void			ft_drawsprite(t_all *all);
void			ft_sortsprites(t_all *all);
void			ft_calculate_lineheight(t_all *all);
void			ft_castray(t_all *all);
void			ft_calculate_sidedist(t_all *all);
void			ft_raycalc(t_all *all);
void			ft_draw_sprite(t_all *all);
void			ft_sprite_fillcolumn(t_all *all, int stripe);
void			ft_width_height(t_all *all);
void			ft_transformsprite(t_all *all, int i);
void			ft_spritedist(t_all *all);
int				ft_softexit(int nu, t_all *all);
void			ft_assign_color(int *orig, int value);
void			ft_assign_texture(t_tex **tmp, t_tex **orig);
void			ft_toobig(t_all *all, int len_w, int len_h);
#endif
