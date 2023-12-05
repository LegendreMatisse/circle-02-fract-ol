/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:27:33 by mlegendr          #+#    #+#             */
/*   Updated: 2023/11/27 17:00:15 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

char		*ft_strnstr(const char *to_search, const char *to_find, size_t st);
int			ft_isalpha(int a);
int			ft_isdigit(int a);
int			ft_isalnum(int a);
int			ft_isascii(int a);
int			ft_isprint(int a);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *str, int a, size_t st);
void		ft_bzero(void *str, size_t st);
void		*ft_memcpy(void *dest, const void *src, size_t st);
void		*ft_memmove(void *dest, const void *src, size_t st);
size_t		ft_strlcpy(char *dest, const char *src, size_t st);
size_t		ft_strlcat(char *dest, const char *src, size_t st);
int			ft_toupper(int a);
int			ft_tolower(int a);
char		*ft_strchr(const char *str, int a);
char		*ft_strrchr(const char *str, int a);
int			ft_strncmp(const char *str_1, const char *str_2, size_t st);
void		*ft_memchr(void *str, int a, size_t st);
int			ft_memcmp(const void *str_1, const void *str_2, size_t st);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t elements, size_t size);
char		*ft_strdup(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//printf
void		ft_hexconvert(unsigned long num, char x);
int			ft_printhex(unsigned long num, char x);
void		ft_putptr(uintptr_t ptr);
int			ft_printptr(unsigned long long ptr);
char		*ft_utioa(unsigned int num);
int			ft_print_uitoa(unsigned int num);
int			ft_printf(const char *str, ...);
int			ft_printchar(char c);
int			ft_printstr(char *str);
int			ft_printnbr(int num);

//get_next_line
char		*ft_gnl_strchr(char *str, int a);
char		*ft_gnl_strjoin(char *buffer, char *line);
char		*ft_real_join(char *joined_str, char *buffer, char *line);
char		*ft_substr_pre_a(char *line);
char		*ft_substr_post_a(char *line);
char		*ft_make_full_line(char *buffer);
char		*ft_fill_buffer(char *line);
char		*get_next_line(int fd);
size_t		ft_gnl_strlen(const char *str);
void		*ft_gnl_calloc(const size_t elements, const size_t size);

#endif
