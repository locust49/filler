/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:15:31 by slyazid           #+#    #+#             */
/*   Updated: 2019/05/23 19:25:08 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_players
{
	int		p1;
	int		p2;
	char	*p1_name;
	char	*p2_name;
	char	p1_sym;
	char	p2_sym;
}				t_players;

typedef struct	s_point
{
	int	row;
	int	col;
}				t_point;

typedef struct	s_token
{
	char	**map;
	t_point	size;
	char	id;
}				t_token;

void	ft_initialize_params(t_token *board, t_token *piece);
void	set_players(t_players *p, char *line);
void	get_token(t_token *token, char *line, int newline);
int		**ft_allocate_tab(t_point size);

void	ft_heat_one(int **heat, t_token *board);
void	ft_heat_over(int **heat, t_point size);

void	ft_print_matrix(int **tab, t_point size);
#endif

