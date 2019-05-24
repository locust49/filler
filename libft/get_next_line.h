/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:31:53 by slyazid           #+#    #+#             */
/*   Updated: 2018/12/04 15:16:32 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 1337

typedef struct		s_files
{
	int				fd;
	char			*cont;
	struct s_files	*next;
}					t_files;

int					get_next_line(const int fd, char **line);
#endif
