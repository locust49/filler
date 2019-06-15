/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:52:43 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/15 15:27:04 by slyazid          ###   ########.fr       */
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
	ft_putendl_fd("after priority :", 2);
	print_list(*place);
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
	// = if down to up
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

t_point	ft_place_token(int	**heat, t_point size_h, t_token piece)
{
	t_point	place;
	t_point	heat_c;
	t_point	piece_c;	
	t_point i;
	t_point lim;
	t_place	*list;
	int		sum;
	int		count;

	place.row = -size_h.row;
	place.col = -size_h.col;
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
			lim = ft_trim_piece(piece);
			while (++piece_c.row < piece.size.row)
			{
				i.col = 0;
				piece_c.col = -1;
				while (++piece_c.col < piece.size.col)
				{
					if (piece.map[piece_c.row][piece_c.col] == '*'
						&& heat_c.row + i.row < size_h.row 
					   	&& heat_c.col + i.col < size_h.col)
					{
							if (heat[heat_c.row + i.row][heat_c.col + i.col]
									== -2)
								count++;
							if (heat[heat_c.row + i.row][heat_c.col + i.col]
								   	== -1 || (count > 1))
								sum = -1;
							else if (heat[heat_c.row + i.row]
									[heat_c.col + i.col] >= 0 && sum >= 0)
								sum += heat[heat_c.row + i.row]
										[heat_c.col + i .col];
							
					}
					if (piece_c.col == piece.size.col - 1
							&& piece_c.row == piece.size.row - 1
						   	&& count == 1 && sum >= 0)
					{
						place.row = heat_c.row;
						place.col = heat_c.col;
						ft_print_point(place, 2);
						ft_putchar_fd('+', 2);
						ft_print_point(lim, 2);
						if (heat_c.row + lim.row - 1 < size_h.row &&
							   	heat_c.col + piece.size.col - 1 < size_h.col)
								//&& heat[heat_c.row][heat_c.col] >= 0)
							store_available_coords(&list, heat_c, sum);
					}
					i.col += 1;
				}
				i.row += 1;
			}
		}
	}
	print_list(list);
	ft_priority_list(&list);	
	//print_list(list);
	if (list->heat_score == -1 && list->next)
		place = list->next->possibility;
	else
		place = list->possibility;
	ft_putendl_fd("outside priority :", 2);
	print_list(list);
//	if (list->next)
//	place = list->possibility;
	free(list);
	return (place);
}
