/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:11:59 by slyazid           #+#    #+#             */
/*   Updated: 2018/11/14 23:56:44 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static t_files		*ft_create_lst(int fd)
{
	t_files *new;

	new = (t_files*)malloc(sizeof(t_files));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->cont = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

t_files				*ft_find_file(int fd, t_files *myfiles)
{
	t_files *pre;
	t_files *current;

	current = myfiles;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		pre = current;
		current = current->next;
	}
	pre->next = ft_create_lst(fd);
	free(current);
	return (pre->next);
}

int					reading(t_files **f, char **buffer)
{
	int val;

	while ((val = read((*f)->fd, *buffer, BUFF_SIZE) > 0))
	{
		(*f)->cont = ft_strjoin((*f)->cont, *buffer);
		ft_bzero(*buffer, BUFF_SIZE);
		if (ft_strchr((*f)->cont, '\n'))
			break ;
	}
	return (val);
}

int					check(t_files **f, char **line, int val)
{
	if ((*f)->fd < 0 || !line || val < 0)
		return (0);
	if (!(*f)->cont)
		(*f)->cont = ft_strnew(BUFF_SIZE);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	int				val;
	char			*buffer;
	char			*n_line;
	t_files			*f;
	static t_files	*myfiles;

	buffer = ft_strnew(BUFF_SIZE);
	if (!myfiles)
		myfiles = ft_create_lst(fd);
	f = ft_find_file(fd, myfiles);
	if (!check(&f, line, read(f->fd, buffer, 0)))
		return (-1);
	val = reading(&f, &buffer);
	if (!(n_line = ft_strchr(f->cont, '\n')))
	{
		*line = ft_strdup(f->cont);
		if (val == 0 && !*f->cont)
			return (0);
		ft_bzero(f->cont, ft_strlen(f->cont));
		return (1);
	}
	*line = ft_strsub(f->cont, 0, ft_strlen(f->cont) - ft_strlen(n_line));
	f->cont = n_line + 1;
	return (1);
}
