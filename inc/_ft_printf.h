/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 08:50:56 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "ft_printf.h"

# ifndef T_FLAGS
#  define T_FLAGS

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	dot;
	int	hashtag;
	int	space;
	int	plus;
}	t_flags;

# endif

/*
**	FT_PARSE
*/
void	ft_parse(t_list *modules, va_list args);
t_flags	get_flags(char *token);

/*
**	FT_SPLIT_MODULE
*/
t_list	*ft_split_modules(const char *ft_format);
int		is_conversion(char to_check);

/*
**	FT_STRINGIFY
*/
char	*ft_stringify(t_list *modules);

#endif
