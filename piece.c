/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 23:53:01 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/17 01:19:53 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** trim cols conditions ?
** depends on rows too :v
*/

int	ft_check_iter_piece(t_token piece, t_point p,
		t_point h, t_point i)
{
	if (piece.map[p.row][p.col] == '*' && h.row + i.row < piece.msize.row
		&& h.col + i.col < piece.msize.col)
		return (1);
	return (0);
}

int	trim_piece(t_token piece)
{
	t_point	coord;
	t_point	jumper;

	coord.row = 0;
	coord.col = piece.size.col;
	jumper.row = 0;
	jumper.col = 0;
	while (coord.row < piece.size.row && !ft_strchr(piece.map[coord.row], '*'))
		coord.row += 1;
	while (coord.row < piece.size.row && ft_strchr(piece.map[coord.row], '*'))
		coord.row += 1;
	return (coord.row);
}
