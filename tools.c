/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:13:23 by slyazid           #+#    #+#             */
/*   Updated: 2019/05/23 19:23:45 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_matrix(int **tab, t_point size)
{
	int	row;
	int	col;

	row = -1;
	while (++row < size.row)
	{
		col = -1;
		while (++col < size.col)
		{
			ft_putnbr_fd(tab[row][col], 2);
			ft_putchar_fd(' ' ,2);
			ft_putchar_fd(' ' ,2);
			ft_putchar_fd(' ' ,2);
		}
		ft_putchar_fd('\n' ,2);
	}
}

/*
 *	dprintf(2, "player = [%d]\nsize board = %d x %d\nsize token = %d x %d\n", ps.p1, board_size.row, board_size.col, token_size.row, token_size.col);
 *	for (int i = 0; i < board_size.row; i++)
 *	ft_putendl_fd(board[i], 2);
 *	ft_putendl_fd("************************", 2);
 *	for (int j = 0; j < token_size.row; j++)
 *	ft_putendl_fd(token[j], 2);
 */

/* int	main()
 * {
 * 		char*line;
 *
 * 		while (get_next_line(0, &line) > 0)
 * 		{
 * 			ft_putendl_fd(line, 2);
 * 		}
 *	}
 */