/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:05:40 by slyazid           #+#    #+#             */
/*   Updated: 2019/05/23 19:02:34 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialize_params(t_token *board, t_token *piece)
{
	board->size.row = -1;
	board->size.col = -1;
	board->id = 'b';
	piece->size.row = -1;
	piece->size.col = -1;
	piece->id = 'p';
}

void	set_players(t_players *ps, char *line)
{
	ps->p1 = line[10] - 48;
	ps->p1_sym = (ps->p1 == 1) ? 'o' : 'x';
}

void	get_token_size(t_token *token, char *line)
{
	char	**tab_size;
	int		len;

	len = (token->id == 'p') ? 5 : 8;
	tab_size = ft_strsplit(line + len, ' ');
	token->size.row = ft_atoi(tab_size[0]);
	token->size.col = ft_atoi(tab_size[1]);
	free(tab_size);
}

void	get_token(t_token *token, char *line, int newline)
{
	int		count_row;
	char	**mem_piece;

	get_token_size(token, line);
	count_row = -1;
	token->map = (char**)malloc(token->size.row * sizeof(char*));
	mem_piece = token->map;
	if (newline == 4)
		get_next_line(0, &line);
	while (++count_row < token->size.row)
		if (get_next_line(0, &line) > 0 && line)
		{
			token->map[count_row] = ft_strdup(line + newline);
			ft_memdel((void**)&line);
		}
	token->map = mem_piece;
}

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

int		**ft_allocate_tab(t_point size)
{
	int	row;
	int	col;
	int	**tmp;

	tmp = (int**)malloc(size.row * sizeof(int*));
	row = -1;
	while (++row < size.row)
	{
		tmp[row] = (int*)malloc(size.col * sizeof(int));
		col = -1;
		while (++col < size.col)
			tmp[row][col] = 0;
	}
	return (tmp);
}

void	ft_heat_one(int **heat, t_token *board)
{
	int		**tmp_heat;
	int		row;
	int		col;

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
	//play turn; send players + &board;
	//capitalize last token placed in &board;
	//place token;
	free(heat);
	return (1);
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
 * 	char	*line;
 *
 * 	while (get_next_line(0, &line) > 0)
 * 	{
 * 		ft_putendl_fd(line, 2);
 * 	}
 * }
 */

