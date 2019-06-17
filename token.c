/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:52:43 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/17 01:19:16 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_priority_list(t_place **place)
{
	t_place	*tmp;
	t_place	*top;

	tmp = *place;
	top = *place;
	while (tmp->next && (tmp->heat_score == 0 || tmp->heat_score == -1))
		tmp = tmp->next;
	if (!tmp->next && (tmp->heat_score == 0 || tmp->heat_score == -1))
		*place = top;
	else
		*place = tmp;
}

void	store_available_coords(t_place **available, t_point coord, int sum)
{
	t_place *tmp;
	t_place *tmp1;
	t_place	*place;

	tmp = *available;
	place = (t_place*)malloc(sizeof(t_place));
	place->possibility.row = coord.row;
	place->possibility.col = coord.col;
	place->heat_score = sum;
	if (tmp->heat_score <= sum)
	{
		while (tmp->next && tmp->next->heat_score <= place->heat_score)
			tmp = tmp->next;
		tmp1 = tmp->next;
		tmp->next = place;
		tmp->next->next = tmp1;
	}
	else
	{
		place->next = *available;
		available = &place;
	}
}

void	ft_calculate_sum(int ***heat, t_point psum, int *sum, int *count)
{
	(*heat)[psum.row][psum.col] == -2 ? (*count)++ : 0;
	if ((*heat)[psum.row][psum.col] == -1 || (*count > 1))
		*sum = -1;
	if ((*heat)[psum.row][psum.col] >= 0 && *sum >= 0)
		*sum += (*heat)[psum.row][psum.col];
}

void	ft_read_piece(t_point h, t_token piece, int **heat,
		t_place **list)
{
	int		sum;
	int		count;
	t_point	i;
	t_point	p;

	count = 0;
	sum = 0;
	i.row = 0;
	p.row = -1;
	while (++p.row < piece.size.row)
	{
		i.col = 0;
		p.col = -1;
		while (++p.col < piece.size.col)
		{
			if (ft_check_iter_piece(piece, p, h, i) == 1)
				ft_calculate_sum(&heat, ft_sum_point(i, h), &sum, &count);
			if (p.col == piece.size.col - 1 && p.row == piece.size.row - 1
				&& count == 1 && sum >= 0 && h.row + trim_piece(piece) - 1 <
				piece.msize.row && h.col + piece.size.col - 1 < piece.msize.col)
				store_available_coords(list, h, sum);
			i.col += 1;
		}
		i.row += 1;
	}
}

t_point	ft_place_token(int **heat, t_point size_h, t_token piece)
{
	t_point	place;
	t_point	h;
	t_place	*list;

	ft_initialize_list(&list, &place, size_h);
	piece.msize = size_h;
	h.row = -1;
	while (++h.row < size_h.row)
	{
		h.col = -1;
		while (++h.col < size_h.col)
			ft_read_piece(h, piece, heat, &list);
	}
	ft_priority_list(&list);
	place = (list->heat_score == -1 && list->next)
		? list->next->possibility : list->possibility;
	free(list);
	return (place);
}
