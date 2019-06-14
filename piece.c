/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 23:53:01 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/14 03:07:01 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
 * trim cols conditions ?
 * depends on rows too :v
 */

t_point	ft_trim_piece(t_token piece)
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
	return (coord);	
}
