/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 15:02:12 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 18:27:20 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**spl;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	spl = (char**)malloc((1 + ft_strwcount(s, c)) * sizeof(char*));
	if (!spl)
		return (NULL);
	while (s[j] != '\0')
	{
		spl[i] = (char*)malloc((ft_wlength(s + j, c)) * sizeof(char));
		if (!(spl + i))
			return (NULL);
		while (s[j] == c)
			j++;
		spl[i] = ft_strncpy(spl[i], s + j, ft_wlength(s + j, c));
		i++;
		j += ft_wlength(s + j, c);
	}
	spl[ft_strwcount(s, c)] = (void *)0;
	return (spl);
}
