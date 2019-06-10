/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:13:23 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/10 04:56:40 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
void	ft_print_matrix(int **tab, t_point size)
{
	int	row;
	int	col;
	int scol;
	int i;

	i = 0;
	scol = size.col;
	dprintf(2, "%3c ", ' ');
	while (scol-- > 0)
		dprintf(2, "%3d ", i++);
	dprintf(2,"\n");
	row = -1;
	while (++row < size.row)
	{
		col = -1;
		dprintf(2, "%03d ", row);
		while (++col < size.col)
		{
			dprintf(2, "%3d ", tab[row][col]);
/*			ft_putnbr_fd(tab[row][col], 2);
			ft_putchar_fd(' ' ,2);
			ft_putchar_fd(' ' ,2);
			ft_putchar_fd(' ' ,2);*/
		}
		//ft_putchar_fd('\n' ,2);
		dprintf(2, "\n");
	}
}

void	ft_print_token(t_token token)
{
	int	row;

	row = -1;
	while (++row < token.size.row)
			ft_putendl_fd(token.map[row], 2);
}
void	ft_print_point(t_point point, int fd)
{
	ft_putnbr_fd(point.row, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(point.col, fd);
	ft_putstr_fd("\n ", fd);
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
