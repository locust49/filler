/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:13:23 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/17 01:18:26 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	ft_print_matrix(int **tab, t_point size)
{
	int	row;
	int	col;
	int scol;
	int i;

	i = 0;
	scol = size.col;
	dprintf(2, "%3c ", ' ');
	while (scol-- > 0)
		dprintf(2, "%3d ", i++);
	dprintf(2, "\n");
	row = -1;
	while (++row < size.row)
	{
		col = -1;
		dprintf(2, "%03d ", row);
		while (++col < size.col)
			dprintf(2, "%3d ", tab[row][col]);
		dprintf(2, "\n");
	}
}

void	ft_print_token(t_token token)
{
	int	row;

	row = -1;
	while (++row < token.size.row)
		ft_putendl_fd(token.map[row], 2);
}

void	ft_print_point(t_point point, int fd)
{
	ft_putnbr_fd(point.row, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(point.col, fd);
	ft_putstr_fd("\n ", fd);
}

/*
** void	print_list(t_place *list)
**{
**	t_place *tmp;
**
**	tmp = list;
**	while (tmp)
**	{
**		ft_putchar_fd('(', 2);
**		ft_putnbr_fd(tmp->possibility.row, 2);
**		ft_putchar_fd(',', 2);
**		ft_putnbr_fd(tmp->possibility.col, 2);
**		ft_putchar_fd(')', 2);
**		ft_putstr_fd(" - ", 2);
**		ft_putnbr_fd(tmp->heat_score, 2);
**		ft_putstr_fd(" -> ", 2);
**		tmp = tmp->next;
**	}
**	ft_putchar_fd('\n', 2);
**}
*/

void	ft_initialize_list(t_place **list, t_point *place, t_point size_h)
{
	place->row = -size_h.row;
	place->col = -size_h.col;
	*list = (t_place*)malloc(sizeof(t_place));
	(*list)->possibility = *place;
	(*list)->heat_score = -1;
	(*list)->next = NULL;
}

t_point	ft_sum_point(t_point p1, t_point p2)
{
	t_point sum;

	sum.row = p1.row + p2.row;
	sum.col = p1.col + p2.col;
	return (sum);
}
