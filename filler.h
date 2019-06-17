/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:15:31 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/17 01:23:35 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

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
	t_point	msize;
}				t_token;

typedef struct	s_place
{
	t_point			possibility;
	int				heat_score;
	struct s_place	*next;

}				t_place;

/*
**				./initialize_params.c:
*/

void			ft_initialize_params(t_token *board, t_token *piece);
void			set_players(t_players *p, char *line);
void			get_token(t_token *token, char *line, int newline);
int				**ft_allocate_tab(t_point size);

/*
**				./heat_map.c:
*/

void			ft_heat_and_replace(int **heat, t_token *board);
void			ft_heat_over(int **heat, t_point size);

/*
**				./token.c:
*/

t_point			ft_place_token(int	**heat, t_point size_h, t_token piece);

/*
**				./tools.c:
*/
void			ft_print_matrix(int **tab, t_point size);
void			ft_print_token(t_token token);
void			ft_print_point(t_point point, int fd);
t_point			ft_sum_point(t_point p1, t_point p2);

/*
**				./piece.c:
*/

int				trim_piece(t_token piece);
int				ft_check_iter_piece(t_token piece, t_point p,
				t_point h, t_point i);
#endif
