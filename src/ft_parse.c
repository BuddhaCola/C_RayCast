/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 21:56:46 by wtaylor           #+#    #+#             */
/*   Updated: 2021/02/19 16:54:57 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_getparam(char *str, t_all *all)
{
	if (ft_strncmp(str, "R ", 2) == 0)
	{
		if (all->mlx.w || all->mlx.h)
			ft_exit(22);
		ft_getresolution(str, all);
		if (!all->mlx.w || !all->mlx.h)
			ft_exit(20);
	}
	else if (ft_strchr("NSEW", *str))
		ft_gettexture(str, all);
	else if ((ft_strncmp(str, "C ", 2) == 0) || (ft_strncmp(str, "F ", 2) == 0))
		ft_getbgcolor(str, all, *str);
}

void	ft_countsprites(t_all *all, char *str)
{
	while (*str)
		if (*(str++) == '2')
			all->spritecount++;
}

void	ft_makemap(t_list *tmp, t_all *all)
{
	char		**map;
	int			i;

	i = 0;
	if (!(all->mlx.w && all->mlx.we_tex && all->mlx.ea_tex &&
										all->mlx.no_tex && all->mlx.so_tex &&
								all->mlx.ceiling >= 0 && all->mlx.floor >= 0))
		ft_exit(31);
	map = malloc(sizeof(char *) * (all->mapsize + 1));
	while (tmp)
	{
		if (ft_checkforbiddensymbols((char *)(tmp->content), " 210NSEW") < 0)
			ft_exit(32);
		if (tmp->next != 0 && *(char *)(tmp->content) == '\0')
			ft_exit(33);
		ft_countsprites(all, (char *)(tmp->content));
		map[i++] = ft_strdup((char *)tmp->content);
		tmp = tmp->next;
	}
	all->map = map;
	all->sprites = ft_calloc(sizeof(t_sprite), all->spritecount);
	all->mlx.w > all->mlx.h ? (all->mlx.bigside = all->mlx.w) :
	(all->mlx.bigside = all->mlx.h);
	ft_mapvalidation(all);
}

void	ft_parse_file(t_list **head, t_all *all)
{
	t_list		*tmp;

	tmp = *head;
	while (tmp)
	{
		if (ft_strlen((char *)(tmp->content)) > all->mapwidth)
			all->mapwidth = (int)ft_strlen((char *)(tmp->content));
		if ((*(char *)(tmp->content) &&
		ft_strchr("RNSEWCF", (*(char *)(tmp->content)))))
			ft_getparam((char *)tmp->content, all);
		else if ((*(char *)(tmp->content) &&
		ft_strchr(" 1", (*(char *)(tmp->content)))))
			break ;
		else if (*(char *)(tmp->content))
			ft_exit(11);
		tmp = tmp->next;
		all->mapsize--;
	}
	ft_makemap(tmp, all);
}

int		ft_readmap(t_all *all, int fd)
{
	char		*line;
	t_list		*head;

	head = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	all->mapsize = ft_lstsize(head);
	ft_parse_file(&head, all);
	ft_lstclear(&head, free);
	return (0);
}
