/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:11:01 by slyazid           #+#    #+#             */
/*   Updated: 2019/05/23 19:22:53 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_heat_one(int **heat, t_token *board)
{
	int**tmp_heat;
	int	row;
	int	col;

	tmp_heat = heat;
	row = -1;
	while (++row < board->size.row)
	{
		col = -1;
		while (++col < board->size.col)
		{
			if (board->map[row][col] == 'O' || board->map[row][col] == 'o')
			{
				row > 0 && col > 0 && tmp_heat[row - 1][col - 1] != -1 ? tmp_heat[row - 1][col - 1] = 1 : 0; //C
				row > 0 && tmp_heat[row - 1][col] != -1 ? tmp_heat[row - 1][col] = 1 : 0; //B
				row > 0 && col < board->size.col - 1 &&  tmp_heat[row - 1][col + 1] != -1 ? tmp_heat[row - 1][col + 1] = 1 : 0; //D
				row < board->size.row - 1 && col > 0 && tmp_heat[row + 1][col - 1] != -1 ? tmp_heat[row + 1][col - 1] = 1 : 0; //H
				row < board->size.row - 1 &&  tmp_heat[row + 1][col] != -1 ? tmp_heat[row + 1][col] = 1 : 0; //F
				row < board->size.row - 1 && col < board->size.col - 1 && tmp_heat[row + 1][col + 1] != -1 ? tmp_heat[row + 1][col + 1] = 1 : 0; //G
				col > 0 &&  tmp_heat[row][col - 1] != -1 ? tmp_heat[row][col - 1] = 1 : 0; //A
				col < board->size.col - 1 &&  tmp_heat[row][col + 1] != -1 ? tmp_heat[row][col + 1] = 1 : 0; //E
				tmp_heat[row][col] = -1;
			}
			else if (board->map[row][col] == 'X' || board->map[row][col] == 'x')
				heat[row][col] = -2;
		}
	}
}

void	ft_plusplus(int **tmp_heat, t_point coord, t_point board_size, int value)
{
	if ((((((((coord.row > 0 && coord.col > 0 && tmp_heat[coord.row - 1][coord.col - 1] == value)
		|| (coord.row > 0 && tmp_heat[coord.row - 1][coord.col] == value))
		|| (coord.row > 0 && coord.col < board_size.col - 1 &&  tmp_heat[coord.row - 1][coord.col + 1] == value))
		|| (coord.row < board_size.row - 1 && coord.col > 0 && tmp_heat[coord.row + 1][coord.col - 1] == value))
		|| (coord.row < board_size.row - 1 &&  tmp_heat[coord.row + 1][coord.col] == value))
		|| (coord.row < board_size.row - 1 && coord.col < board_size.col - 1 && tmp_heat[coord.row + 1][coord.col + 1] == value))
		|| (coord.col > 0 &&  tmp_heat[coord.row][coord.col - 1] == value))
		|| (coord.col < board_size.col - 1 &&  tmp_heat[coord.row][coord.col + 1] == value))
		tmp_heat[coord.row][coord.col] =  value +1;
}

void	ft_heat_over(int **heat, t_point size)
{
	t_point	coord;
	int	mem;
	int value;

	value = 0;
	mem = size.col;
	while (mem--)
	{
		coord.row = -1;
		while (++(coord.row) < size.row)
		{
			coord.col = -1;
			while (++(coord.col) < size.col)
				if (heat[coord.row][coord.col] == 0)
					ft_plusplus(heat, coord, size, value + 1);
		}
		value++;
	}
}
