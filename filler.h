/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 04:15:31 by slyazid           #+#    #+#             */
/*   Updated: 2019/05/23 18:12:24 by slyazid          ###   ########.fr       */
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

#endif

