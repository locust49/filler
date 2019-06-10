/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:52:43 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/10 05:09:01 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
void	print_list(t_place *list)
{
	t_place *tmp;

	tmp = list;
	while (tmp)
	{
		ft_putchar_fd('(', 2);
		ft_putnbr_fd(tmp->possibility.row ,2);
		ft_putchar_fd(',', 2);
		ft_putnbr_fd(tmp->possibility.col ,2);
		ft_putchar_fd(')', 2);
		ft_putstr_fd(" - " ,2);
		ft_putnbr_fd(tmp->heat_score, 2);
		ft_putstr_fd(" -> ", 2);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 2);	
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
	if (tmp->heat_score < sum)
	{
		while (tmp && tmp->next && tmp->next->heat_score < place->heat_score)
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

t_point	ft_place_token(int	**heat, t_point size_h, t_token piece)
{
	t_point	place;
	t_point	heat_c;
	t_point	piece_c;	
	t_point i;
	t_place	*list;
	int		sum;
	int		count;

	place.row = -1;
	place.col = -1;
	heat_c.row = -1;
	list = (t_place*)malloc(sizeof(t_place));
	list->possibility = place;
	list->heat_score = -1;
	list->next = NULL;
	while (++heat_c.row < size_h.row)
	{
		heat_c.col = -1;
		while (++heat_c.col < size_h.col)
		{
			count = 0;
			piece_c.row = -1;
			i.row = 0;
			sum = 0;
			while (++piece_c.row < piece.size.row)
			{
				i.col = 0;
				piece_c.col = -1;
				while (++piece_c.col < piece.size.col)
				{
					if (piece.map[piece_c.row][piece_c.col] == '*'
						&& heat_c.row + i.row < size_h.row 
					   	&& heat_c.col + i.col < size_h.col
						&& (heat[heat_c.row + i.row][heat_c.col + i.col] == -2 || heat[heat_c.row + i.row][heat_c.col + i.col] > 0))
					{
							if (heat[heat_c.row + i.row][heat_c.col + i.col] == -2)
								count++;
							if (heat[heat_c.row + i.row][heat_c.col + i .col] > 0)
								sum += heat[heat_c.row + i.row][heat_c.col + i .col];
					}
					if (piece_c.col == piece.size.col - 1
							&& piece_c.row == piece.size.row - 1 && count == 1 && sum > 1)
					{
						place.row = heat_c.row;
						place.col = heat_c.col;
						if (heat_c.row + piece.size.row < size_h.row && heat_c.col + piece.size.col < size_h.col
								&& heat[heat_c.row][heat_c.col] > 0)
							store_available_coords(&list, heat_c, sum);
					}
					i.col += 1;
				}
				i.row += 1;
			}
		}
	}
	print_list(list);
	place = (list->next ? list->next->possibility : list->possibility);
	free(list);
	return (place);
}
