/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:43:37 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/28 16:00:14 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../lib/libft/libft.h"

# define CONVERSIONS "uxXipd%sc"

typedef struct s_flags
{
	int	minus;
	int zero;
	int dot;
	int hashtag;
	int space;
	int plus;
}	t_flags;

int		ft_printf(const char *str, ...)
		__attribute__ ((format (printf, 1, 2)));

t_list	 *ft_split_modules(const char *ft_format);
int		ft_is_flag(char c);
void	ft_parse(t_list **modules, va_list args);
char	*ft_stringify(t_list **modules);
t_flags	decompose_pur_flags(t_list module);
void	decompose_numbered_flags(t_list *module, t_flags *flags, int *i);

#endif
