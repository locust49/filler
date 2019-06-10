/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:05:40 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/10 04:46:44 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_verify_edges(int **heat, t_point coord, t_point board_size)
{
/*	if ((((((((coord.row > 0 && coord.col > 0
			&& heat[coord.row - 1][coord.col - 1] == -2)
		|| (coord.row > 0 && heat[coord.row - 1][coord.col] == -2))
		|| (coord.row > 0 && coord.col < board_size.col - 1
			&& heat[coord.row - 1][coord.col + 1] == -2))
		|| (coord.row < board_size.row - 1 && coord.col > 0
			&& heat[coord.row + 1][coord.col - 1] == -2))
		|| (coord.row < board_size.row - 1
			&& heat[coord.row + 1][coord.col] == -2))
		|| (coord.row < board_size.row - 1 && coord.col < board_size.col - 1
			&& heat[coord.row + 1][coord.col + 1] == -2))
		|| (coord.col > 0 &&  heat[coord.row][coord.col - 1] == -2))
		|| (coord.col < board_size.col - 1
			&&  heat[coord.row][coord.col + 1] == -2))*/
	(void)board_size;
	if (heat[coord.row][coord.col] == -2)// && heat[coord.row][coord.col] != -1)
		return (1);
	return (0);
}

int		ft_verify_shape(t_token piece, int **heat, t_point size, t_point curr)
{
	t_point	coord;
	t_point	sum;

	coord.row = -1;
	while (++coord.row < piece.size.row)
	{
		coord.col = -1;
		while (++coord.col < piece.size.col)
		{
			sum.row = curr.row + coord.row;
			sum.col = curr.col + coord.col;
			if (sum.row < size.row && heat[sum.row][sum.col] != -1)
			{
//				if heat[sum.row][sum.col] == -2)
			}
		}
	}
return (1);
}

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
		&& (coord.col > 0 &&  heat[coord.row][coord.col - 1] != -1))
		&& (coord.col < board_size.col - 1
			&&  heat[coord.row][coord.col + 1] != -1))
		return (1);
	return (0);

}

/*t_point	ft_place_token(int	**heat, t_point size_h, t_token piece)
{
	t_point	coord;
	t_point	c_heat;
	t_point c_piece;
	t_point	c_sum;
	int		count;

	coord.row = -1;
	coord.col = -1;
	c_heat.row = -1;
	while (++c_heat.row < size_h.row)
	{
		c_heat.col = -1;
		while (++c_heat.col < size_h.col)
		{
			count = 0;
			c_piece.row = -1;
				while (++c_piece.row < piece.size.row)
				{
					c_piece.col = -1;
					while (++c_piece.col < piece.size.col)
					{
						c_sum.row = c_piece.row + c_heat.row;
						c_sum.col = c_piece.col + c_heat.col;
						if (piece.map[c_piece.row][c_piece.col] == '*' && ft_verify_edges(heat, c_sum, size_h)
						//		&& c_sum.row < size_h.row && c_sum.col < size_h.col
						//		&& heat[c_sum.row][c_sum.col] != -1
								&& ft_check_free(heat, c_sum, size_h)
								)
						{
							ft_print_point(c_sum, 2);
							ft_putnbr_fd(heat[c_sum.row][c_sum.col], 2);
							ft_putstr_fd("\n", 2);
							
//							if (ft_verify_edges(heat, c_sum, size_h))
								count += 1;
						//	if (c_sum.row < size_h.row && c_sum.col < size_h.col
								&& heat[c_sum.row][c_sum.col] != -1)//
						}
						if (c_piece.col == piece.size.col - 1
								&& c_piece.row == piece.size.row - 1 && count == 1)
						{
							coord.row = c_heat.row;
							coord.col = c_heat.col;
						//	if (heat[c_heat.row][c_heat.col] > 0)
						//	{
								ft_print_point(coord, 2);
								ft_putnbr_fd(heat[coord.row][coord.col], 2);
								ft_putstr_fd("\n\ncount:\n", 2);
								ft_putnbr_fd(count, 2);
								return (coord);	
						//	}
						}
					}
				}
		//	else
		//	{
		//		ft_putnbr_fd(heat[c_heat.row][c_heat.col], 2);
		//		ft_putstr_fd("\n\n", 2);
		//	}
		}
	}
	return (coord);
}*/


int	main()
{
	char		*line;
	t_players	ps;
	t_token		board;
	t_token		piece;
	int			**heat;
	t_point		coord;

	ft_initialize_params(&board, &piece);
	coord.row = -1;
	coord.col = -1;
	while (get_next_line(0, &line))
	{
		!ft_strstr(line, "$$$ exec ") ? 0 : set_players(&ps, line);
		!ft_strstr(line, "Plateau ") ? 0 : get_token(&board, line, 4);
		if (ft_strstr(line, "Piece "))
		{
			get_token(&piece, line, 0);
			heat = ft_allocate_tab(board.size);
			ft_heat_one(heat, &board);
			ft_heat_over(heat, board.size);
			coord = ft_place_token(heat, board.size, piece);
			ft_print_matrix(heat, board.size);
			ft_print_point(coord, 1);
			ft_print_point(coord, 2);
		}
		free(line);
	}
	free(heat);
	return (1);
}

/*
 * play turn; send players + &board;
 * capitalize last token placed in &board;
 * place token;
 */
