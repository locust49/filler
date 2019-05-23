/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:05:40 by slyazid           #+#    #+#             */
/*   Updated: 2019/05/23 06:44:09 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialize_params(t_point *board, t_point *token)
{
	board->row = -1;
	board->col = -1;
	token->row = -1;
	token->col = -1;
}

void	set_players(t_players *ps, char *line)
{
	ps->p1 = line[10] - 48;
	ps->p1_sym = (ps->p1 == 1) ? 'o' : 'x';
}

t_point	get_board_size(char *line)
{
	char	**tab_size;
	t_point	board_size;

	tab_size = ft_strsplit(line + 8, ' ');
	board_size.row = ft_atoi(tab_size[0]);
	board_size.col = ft_atoi(tab_size[1]);
	free(tab_size);
	return (board_size);
}

t_point	get_token_size(char *line)
{
	char	**tab_size;
	t_point	token_size;

	tab_size = ft_strsplit(line + 5, ' ');
	token_size.row = ft_atoi(tab_size[0]);
	token_size.col = ft_atoi(tab_size[1]);
	free(tab_size);
	return (token_size);
}

void	get_piece(char ***piece, t_point piece_size, int newline)
{
	int		count_row;
	char	*line;
	char	**mem_piece;

	count_row = -1;
	*piece = (char**)malloc(piece_size.row * sizeof(char*));
	mem_piece = *piece;
	if (newline == 4)
		get_next_line(0, &line);
	while (++count_row < piece_size.row)
		if (get_next_line(0, &line) > 0 && line)
		{
			**piece = ft_strdup(line + newline);
			(*piece)++;
			ft_memdel((void**)&line);
		}
	*piece = mem_piece;
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

void	ft_heat_one(int **heat, char **board, t_point board_size)
{
	int		**tmp_heat;
	int		row;
	int		col;

	tmp_heat = heat;
	row = -1;
	while (++row < board_size.row)
	{
		col = -1;
		while (++col < board_size.col)
		{
			if (board[row][col] == 'O' || board[row][col] == 'o')
			{
				row > 0 && col > 0 && tmp_heat[row - 1][col - 1] != -1 ? tmp_heat[row - 1][col - 1] = 1 : 0; //C
				row > 0 && tmp_heat[row - 1][col] != -1 ? tmp_heat[row - 1][col] = 1 : 0; //B
				row > 0 && col < board_size.col - 1 &&  tmp_heat[row - 1][col + 1] != -1 ? tmp_heat[row - 1][col + 1] = 1 : 0; //D
				row < board_size.row - 1 && col > 0 && tmp_heat[row + 1][col - 1] != -1 ? tmp_heat[row + 1][col - 1] = 1 : 0; //H
				row < board_size.row - 1 &&  tmp_heat[row + 1][col] != -1 ? tmp_heat[row + 1][col] = 1 : 0; //F
				row < board_size.row - 1 && col < board_size.col - 1 && tmp_heat[row + 1][col + 1] != -1 ? tmp_heat[row + 1][col + 1] = 1 : 0; //G
				col > 0 &&  tmp_heat[row][col - 1] != -1 ? tmp_heat[row][col - 1] = 1 : 0; //A
				col < board_size.col - 1 &&  tmp_heat[row][col + 1] != -1 ? tmp_heat[row][col + 1] = 1 : 0; //E
				tmp_heat[row][col] = -1;
			}
			else if (board[row][col] == 'X' || board[row][col] == 'x')
				heat[row][col] = -2;
		}
	}
}

void	ft_plusplus(int **tmp_heat, int row, int col, t_point board_size, int value)
{
	if ((((((((row > 0 && col > 0 && tmp_heat[row - 1][col - 1] == value)
		|| (row > 0 && tmp_heat[row - 1][col] == value))
		|| (row > 0 && col < board_size.col - 1 &&  tmp_heat[row - 1][col + 1] == value))
		|| (row < board_size.row - 1 && col > 0 && tmp_heat[row + 1][col - 1] == value))
		|| (row < board_size.row - 1 &&  tmp_heat[row + 1][col] == value))
		|| (row < board_size.row - 1 && col < board_size.col - 1 && tmp_heat[row + 1][col + 1] == value))
		|| (col > 0 &&  tmp_heat[row][col - 1] == value))
		|| (col < board_size.col - 1 &&  tmp_heat[row][col + 1] == value))
			tmp_heat[row][col] =  value +1;
}

void	ft_heat_over(int **heat, t_point size)
{
	int	row;
	int	col;
	int	mem;
	int value;

	value = 0;
	mem = size.col;
	while (mem--)
	{
		row = -1;
		while (++row < size.row)
		{
			col = -1;
			while (++col < size.col)
				if (heat[row][col] == 0)
					ft_plusplus(heat, row, col, size, value + 1);
		}
		value++;
	}
}

int	main()
{
	char		*line;
	int			no;
	t_players	ps;
	t_point		board_size;
	t_point		token_size;
	char		**board;
	int			**heat;
	char		**token;

	ft_initialize_params(&board_size, &token_size);
	no = 1;
	while (get_next_line(0, &line) > 0)
	{
		if (no == 1)
			set_players(&ps, line);
		else
		{
			if (ft_strstr(line, "Plateau "))
			{
				board_size = get_board_size(line);
				get_piece(&board, board_size, 4);
			}
			if (ft_strstr(line, "Piece "))
			{
				token_size = get_token_size(line);
				get_piece(&token, token_size, 0);
			}
		}
		heat = ft_allocate_tab(board_size);
		ft_heat_one(heat, board, board_size);
		ft_heat_over(heat, board_size);

		//play turn; send players + &board;
		no++;
		//capitalize last token placed in &board;
		//place token;
	}
	ft_print_matrix(heat, board_size);
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

