/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:13:23 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/17 03:10:27 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_point(t_point point, int fd)
{
	ft_putnbr_fd(point.row, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(point.col, fd);
	ft_putstr_fd("\n ", fd);
}

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
