/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcourtem <jcourtem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:38:30 by JEAN-SEBA         #+#    #+#             */
/*   Updated: 2022/04/08 12:51:50 by jcourtem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void			*ft_memset(void *str, int c, size_t len);

void			ft_bzero(void *str, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			*ft_memccpy(void *dest, const void *src, int c, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t n);

void			*ft_memchr(void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

size_t			ft_strlen(const char *s);

int				ft_isalpha(int c);

int				ft_isdigit(int c);

int				ft_isalnum(int c);

int				ft_isascii(int c);

int				ft_isprint(int c);

int				ft_toupper(int c);

int				ft_tolower(int c);

char			*ft_strchr(char *s, int c);

char			*ft_strrchr(char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);

size_t			ft_strlcat(char *dest, const char *src, size_t dest_size);

char			*ft_strnstr(const char *haystack, const char *needle, \
		size_t len);

int				ft_atoi(const char *str);

void			*ft_calloc(size_t count, size_t size);

char			*ft_strdup(const char *s1);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strtrim(char const *s1, char const *set);

char			**ft_split(char const *s, char c);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

int				ft_islower(int c);

int				ft_isupper(int c);

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **alst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **alst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
		void (*del)(void *));

void			ft_putchar_fd(char c, int fd);

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

void			ft_putptr_fd(void *ptr, int fd);

void			ft_puthex_fd(int hex, int fd);

void			ft_putfloat_fd(float i, int fd);

int				ft_intversion(int i);

void			ft_intversion_test(int base, int expected);

char			*ft_itohex(long i);

void			ft_itohex_test(void);

char			*get_next_line(int fd);

char			*gnl_strchr(char *s, char c);

char			*gnl_strcat(char *dest, char *src);

void			gnl_memmove(char *dest, char *src, int size);

unsigned int	make_hex(unsigned long long va, int *hex);

size_t			ft_strlen(const char *s);

void			ft_putnbr(int n);

long			ft_atol(const char *str);

// libftprintf: 
unsigned int	make_hex(unsigned long long va, int *hex);
size_t			ft_strlen(const char *s);
void			ft_putnbr(int n);
int				ft_printf(const char *str, ...);
void			ft_check_flag(const char flag, va_list ap, int *pt_count);
int				ft_put_i(va_list ap);
void			ft_put_p(va_list ap, int *pt_count);
void			ft_put_s(va_list ap, int *pt_count);
void			ft_put_u(va_list ap, int *pt_count);
void			ft_put_h(va_list ap, int *pt_count);
void			ft_put_upperh(va_list ap, int *pt_count);
int				ft_put_c(char c);
int				ft_intlen(int x);
int				ft_uintlen(unsigned int x);
int				ft_put_percent(const char *str, int i, int *pt_count);
int				ft_printf(const char *str, ...);

#endif
