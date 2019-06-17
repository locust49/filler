/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:05:40 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/17 02:53:13 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check_free(int **heat, t_point coord, t_point board_size)
{
	if ((((((((coord.row > 0 && coord.col > 0
			&& heat[coord.row - 1][coord.col - 1] != -1)
		&& (coord.row > 0 && heat[coord.row - 1][coord.col] != -1))
		&& (coord.row > 0 && coord.col < board_size.col - 1
			&& heat[coord.row - 1][coord.col + 1] != -1))
		&& (coord.row < board_size.row - 1 && coord.col > 0
			&& heat[coord.row + 1][coord.col - 1] != -1))
		&& (coord.row < board_size.row - 1
			&& heat[coord.row + 1][coord.col] != -1))
		&& (coord.row < board_size.row - 1 && coord.col < board_size.col - 1
			&& heat[coord.row + 1][coord.col + 1] != -1))
		&& (coord.col > 0 && heat[coord.row][coord.col - 1] != -1))
		&& (coord.col < board_size.col - 1
			&& heat[coord.row][coord.col + 1] != -1))
		return (1);
	return (0);
}

int		**fill_it(t_token board, char *line, t_players ps)
{
	t_token	piece;
	int		**heat;
	t_point	coord;

	ft_initialize_params(NULL, &piece);
	get_token(&piece, line, 0);
	heat = ft_allocate_tab(board.size);
	ft_heat_and_replace(heat, &board, ps);
	ft_heat_over(heat, board.size);
	coord = ft_place_token(heat, board.size, piece);
	ft_print_point(coord, 1);
	piece.map ? free(piece.map) : 0;
	return (heat);
}

int		main(void)
{
	char		*line;
	t_players	ps;
	t_token		token;
	int			**heat;
	t_point		coord;

	ft_initialize_params(&token, NULL);
	coord.row = -1;
	coord.col = -1;
	while (get_next_line(0, &line))
	{
		!ft_strstr(line, "$$$ exec ") ? 0 : set_players(&ps, line);
		!ft_strstr(line, "Plateau ") ? 0 : get_token(&token, line, 4);
		heat = ft_strstr(line, "Piece ") ? fill_it(token, line, ps) : 0;
		line ? free(line) : 0;
	}
	free(token.map);
	heat ? free(heat) : 0;
	return (1);
}
