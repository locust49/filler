/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:08:15 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/17 02:19:59 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialize_params(t_token *board, t_token *piece)
{
	if (board)
	{
		board->size.row = -1;
		board->size.col = -1;
		board->id = 'b';
	}
	if (piece)
	{
		piece->size.row = -1;
		piece->size.col = -1;
		piece->id = 'p';
	}
}

void	set_players(t_players *ps, char *line)
{
	ps->p1 = line[10] - 48;
	ps->p1_sym = (ps->p1 == 1) ? 'o' : 'x';
	ps->p2 = (ps->p1 == 1) ? 2 : 1;
	ps->p2_sym = (ps->p2 == 1) ? 'o' : 'x';
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
