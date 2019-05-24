/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:05:40 by slyazid           #+#    #+#             */
/*   Updated: 2019/05/23 19:23:30 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main()
{
	char		*line;
	t_players	ps;
	t_token		board;
	t_token		piece;
	int			**heat;

	ft_initialize_params(&board, &piece);
	while (get_next_line(0, &line) > 0)
	{
		!ft_strstr(line, "$$$ exec ") ? 0 : set_players(&ps, line);
		!ft_strstr(line, "Plateau ") ? 0 : get_token(&board, line, 4);
		!ft_strstr(line, "Piece ") ? 0 : get_token(&piece, line, 0);
	}
	heat = ft_allocate_tab(board.size);
	ft_heat_one(heat, &board);
	ft_heat_over(heat, board.size);
	ft_print_matrix(heat, board.size);
	free(heat);
	return (1);
}

/*
 * play turn; send players + &board;
 * capitalize last token placed in &board;
 * place token;
 */
