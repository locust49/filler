/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:11:01 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/16 04:33:25 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_heat_one(t_point i, int **tmp, t_token *map)
{
	i.row > 0 && i.col > 0 && tmp[i.row - 1][i.col - 1] != -1
		&& tmp[i.row - 1][i.col - 1] != -2 ? tmp[i.row - 1][i.col - 1] = 1 : 0;
	i.row > 0 && tmp[i.row - 1][i.col] != -1 && tmp[i.row - 1][i.col] != -2 ?
		tmp[i.row - 1][i.col] = 1 : 0;
	i.row > 0 && i.col < map->size.col - 1 && tmp[i.row - 1][i.col + 1] != -1
		&& tmp[i.row - 1][i.col + 1] != -2 ? tmp[i.row - 1][i.col + 1] = 1 : 0;
	i.row < map->size.row - 1 && i.col > 0 && tmp[i.row + 1][i.col - 1] != -1
		&& tmp[i.row + 1][i.col - 1] != -2 ? tmp[i.row + 1][i.col - 1] = 1 : 0;
	i.row < map->size.row - 1 && tmp[i.row + 1][i.col] != -1
		&& tmp[i.row + 1][i.col] != -2 ? tmp[i.row + 1][i.col] = 1 : 0;
	i.row < map->size.row - 1 && i.col < map->size.col - 1
		&& tmp[i.row + 1][i.col + 1] != -1 && tmp[i.row + 1][i.col + 1] != -2 ?
		tmp[i.row + 1][i.col + 1] = 1 : 0;
	i.col > 0 && tmp[i.row][i.col - 1] != -1 && tmp[i.row][i.col - 1] != -2 ?
		tmp[i.row][i.col - 1] = 1 : 0;
	i.col < map->size.col - 1 && tmp[i.row][i.col + 1] != -1
		&& tmp[i.row][i.col + 1] != -2 ? tmp[i.row][i.col + 1] = 1 : 0;
	tmp[i.row][i.col] = -1;
}

void	ft_heat_and_replace(int **heat, t_token *map)
{
	int		**tmp;
	t_point	i;

	tmp = heat;
	i.row = -1;
	while (++i.row < map->size.row)
	{
		i.col = -1;
		while (++i.col < map->size.col)
		{
			if (map->map[i.row][i.col] == 'O' || map->map[i.row][i.col] == 'o')
			{
				ft_heat_one(i, tmp, map);
				tmp[i.row][i.col] = -1;
			}
			else if (map->map[i.row][i.col] == 'X'
					|| map->map[i.row][i.col] == 'x')
				tmp[i.row][i.col] = -2;
		}
	}
}

void	ft_plusplus(int **tmp, t_point coord, t_point map_size, int value)
{
	if ((((((((coord.row > 0 && coord.col > 0
					&& tmp[coord.row - 1][coord.col - 1] == value)
				|| (coord.row > 0 && tmp[coord.row - 1][coord.col] == value))
				|| (coord.row > 0 && coord.col < map_size.col - 1
					&& tmp[coord.row - 1][coord.col + 1] == value))
				|| (coord.row < map_size.row - 1 && coord.col > 0
					&& tmp[coord.row + 1][coord.col - 1] == value))
				|| (coord.row < map_size.row - 1
					&& tmp[coord.row + 1][coord.col] == value))
				|| (coord.row < map_size.row - 1 && coord.col < map_size.col - 1
					&& tmp[coord.row + 1][coord.col + 1] == value))
				|| (coord.col > 0 && tmp[coord.row][coord.col - 1] == value))
				|| (coord.col < map_size.col - 1
					&& tmp[coord.row][coord.col + 1] == value))
		tmp[coord.row][coord.col] = value + 1;
}

void	ft_heat_over(int **heat, t_point size)
{
	t_point	coord;
	int		mem;
	int		value;

	value = 0;
	mem = size.col;
	while (mem-- >= 0)
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
