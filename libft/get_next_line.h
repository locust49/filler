/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:31:53 by slyazid           #+#    #+#             */
/*   Updated: 2019/06/04 08:02:04 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 1337

typedef	struct	s_buff
{
	int				fd;
	char			*data;
	struct s_buff	*previous;
	struct s_buff	*next;
}				t_buff;

int				get_next_line(const int fd, char **line);
#endif
