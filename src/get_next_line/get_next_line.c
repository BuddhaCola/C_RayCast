/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:33:54 by wtaylor           #+#    #+#             */
/*   Updated: 2020/12/10 22:23:09 by wtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_calloc(size_t count, size_t size)
{
	char *p;

	if (!(p = (char *)malloc(count * size)))
		return (NULL);
	while (size--)
		p[size] = '\0';
	return (p);
}

int				ft_cut(char **heap, char **line)
{
	char *n_ptr;
	char *temp;

	if (*heap && (n_ptr = ft_strchr(*heap, '\n')))
	{
		*n_ptr = '\0';
		*line = ft_strdup(*heap);
		temp = *heap;
		*heap = ft_strdup(++n_ptr);
		free(temp);
		return (1);
	}
	else if (*heap && (n_ptr = ft_strchr(*heap, '\0')))
	{
		*line = ft_strdup(*heap);
		free(*heap);
		*heap = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	char static	*heap;
	int			idx;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || !line)
		return (-1);
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * (sizeof(char)))))
		return (-1);
	while ((idx = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[idx] = '\0';
		if (!heap)
			heap = ft_strdup(buf);
		else
		{
			tmp = heap;
			heap = ft_strjoin(heap, buf);
			free(tmp);
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (ft_cut(&heap, line));
}
