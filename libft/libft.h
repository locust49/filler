/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slyazid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 18:43:18 by slyazid           #+#    #+#             */
/*   Updated: 2018/10/26 18:18:29 by slyazid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list	t_list;
struct				s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
};

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_memchr(const void *s, int c, size_t n);

size_t				ft_strlen(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

int					ft_atoi(const char *str);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t len);

char				*ft_strdup(const char *s1);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strstr(const char *haystack, const char *needle);

char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

void				ft_putchar(char c);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr(char const *s);

void				ft_putstr_fd(const char *s, int fd);

void				ft_putendl(char const *s);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr(int n);

void				ft_putnbr_fd(int n, int fd);

void				ft_strdel(char **as);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

t_list				*ft_lstnew(void const *content, size_t content_size);

void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void				ft_lstadd(t_list **alst, t_list *new);

void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

unsigned int		ft_strwcount(const char *str, char c);

unsigned int		ft_wlength(const char *str, char c);

size_t				ft_lstsize(t_list *lst);

t_list				*ft_lstdel_elt(t_list *lst, int index);

void				ft_putlst(t_list *lst);

t_list				*ft_lstadd_elt(t_list *lst, t_list *new, int index);

char				*ft_trim_delim(char const *s, char c);
#endif
