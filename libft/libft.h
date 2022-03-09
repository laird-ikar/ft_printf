/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:24:47 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 12:22:40 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

# ifndef T_LIST
#  define T_LIST

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# endif

int		ft_isspace(char c);
/* Return true if c is a whitespace, false otherwise */
int		ft_isalpha(int c);
/* Return true if c is a letter, false otherwise */
int		ft_isdigit(int c);
/* Return true if c is a digit, false otherwise */
int		ft_isalnum(int c);
/* Return true if c is a letter or a digit, false otherwise */
int		ft_isascii(int c);
/* Return true if c is an ascii char, false otherwise */
int		ft_isprint(int c);
/* Return true if c is a printable char, false otherwise */
int		ft_toupper(int c);
/* Return the upper conterpart of c if c is a lower letter, c otherwise */
int		ft_tolower(int c);
/* Return the lower conterpart of c if c is a upper letter, c otherwise */
int		ft_strcmp(const char *s1, const char *s2);
/* Compare the strings s1 and s2, char by char
** and return the first diffrence (is ascii value) */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/* Compare the at most n first chars of s1 and s2
** and return the first diffrence (is ascii value) */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/* Compare the at most n first bytes of s1 and s2
** and return the first diffrence */
int		ft_atoi(const char *str);
/* Return the number representing by str, skiping the firsts white spaces */
int		ft_lstsize(t_list *lst);
/* Return the number of element of the list lst*/
int		ft_strcontain(char **src, char *tofind);
/* Return 1 if there is tofind in src, 0 other wise*/
int		ft_tabmin(int *tab, size_t size);
/* Return the minimum of the array */
int		ft_tabmax(int *tab, size_t size);
/* Return the minimum of the array */
int		ft_tabmed(int *tab, int size);
/* Return the med of the array */
int		ft_abs(int a);
/* Return absolute value of a */

void	ft_bzero(void *s, size_t n);
/* Fill n byte of memory, at the address of s with 0s */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/* Apply the function f to each char of s */
void	ft_putchar_fd(char c, int fd);
/* Write the char c in the given fd */
void	ft_putstr_fd(char *s, int fd);
/* Write the string s in the given fd */
void	ft_putendl_fd(char *s, int fd);
/* Write the string s in the given fd with a line break */
void	ft_putnbr_fd(int n, int fd);
/* Write a strnig representing n in the given fd */
void	ft_lstadd_front(t_list **lst, t_list *new);
/* Add the new list at the begining of the list pointed by lst */
void	ft_lstadd_back(t_list **lst, t_list *new);
/* Add the new list at the end of the list pointed by lst */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/* Free the memory of the content of lst with del THEN free
** DO NOT free the next element */
void	ft_lstclear(t_list **lst, void (*del)(void *));
/* Free the memory of the content of lst with del THEN free
** DO free the next element and set the original pointer to NULL */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/* Apply f to every element of lst */

size_t	ft_strlen(const char *s);
/* Return the size of s */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
/* Copy at most dstsize - 1 chars from src to dst,
** \0 terminate dst and return the original size of src */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
/* Concatenate dst and src, for at most dstsize char and return
** the initial size of dst + the size of src */

void	*ft_memset(void *b, int c, size_t len);
/* Fill n byte of memory at the b address with the value of c */
void	*ft_memcpy(void *dst, void *src, size_t n);
/* Copy n byte of memory from src to dst */
void	*ft_memmove(void *dst, const void *src, size_t len);
/* Copy n byte of memory from src to dst in a
** non destructive way (safer if overlap) */
void	*ft_memchr(const void *s, int c, size_t n);
/* Return the address of the first occurence of
** c in the n bytes of memory pointed by s */
void	*ft_calloc(size_t count, size_t size);
/* Allocate size byte of memeory and set them to 0
** (return NULL if allocation fails) */
void	*ft_memcat(const void *mem1, const void *mem2,
			size_t len1, size_t len2);
/* Allocate and return the contatenation of mem1 and mem2
** (return NULL if allocation fails)*/

char	*ft_strchr(const char *s, int c);
/* Return the address of the first occurence of c in the string pointed by s */
char	*ft_strrchr(const char *s, int c);
/* Return the address of the last occurence of c in the string pointed by s */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/* Return the address of the first occurence of needle in haystack */
char	*ft_strdup(const char *s1);
/* Allocate and return a copy of s1 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/* Allocate and return the substring starting at the index start
** of lenght len (NULL if allocation fails) */
char	*ft_strjoin(char const *s1, char const *s2);
/* Allocate and return the concatenation of s1 and s2
** (NULL if allocation fails) */
char	*ft_strtrim(char const *s1, char const *set);
/* Allocate and return a substring of s1
** without begining and end char that are present in set
** (NULL if allocation fails) */
char	*ft_itoa(int n);
/* Return the string representation of the integer n
** (NULL if allocation fails) */
char	*ft_utoa(unsigned int n);
/* Return the string representation of unsigned integer n
** (NULL if allocation fails) */
char	*ft_utoa_base(unsigned int nb, char *base);
/* Return the string representation of unsigned int n, in the given base
** (NULL if allocation fails) */
char	*ft_ultoa_base(unsigned long nb, char *base);
/* Return the string representation of unsigned long n, in the given base
** (NULL if allocation fails) */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/* Allocate and return a string of f(i, s[i]) (NULL if allocation fails) */

t_list	*ft_lstnew(void *content);
/* Create and return a new list with first element content, and a NULL next
** (NULL if allocation fails) */
t_list	*ft_lstlast(t_list *lst);
/* Return the lat element of a list */
t_list	*ft_lstcalendar(const t_list *lst, size_t calendar);
/* Return the calendarth element of lst */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
/* Return the list of the images of lst by f (NULL if allocation fails) */

char	**ft_split(char const *s, char c);
/* Allocate and return a tab of substring of s
** , cuting s along c (NULL if allocation fails) */

#endif
