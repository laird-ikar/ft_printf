/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/30 08:48:02 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "ft_printf.h"

# ifndef T_FLAG
#  define T_FLAG

typedef struct s_flag
{
	char	conv_type;
	char	padding_type;
	char	positive_sign;
	int		do_alt_form;
	int		min_width;
	int		precision;
}	t_flag;

# endif

# ifndef T_PARSE
#  define T_PARSE

typedef char	*(t_parse)(va_list, t_flag);

# endif

# ifndef FT_CONVERSIONS
#  define FT_CONVERSIONS "uxXipd%sc"
# endif

# ifndef FT_FLAGS
#  define FT_FLAGS " 0-+#"
# endif

/*
 *	FT_PARSE
 */
void	ft_parse(t_list *module, va_list args);
t_flag	get_flag(char *token);
void	parse_flag(t_flag *flag_struct, char flag_char);

/*
 *	EXPEND_ARG
 */
char	*expend_arg(va_list args, t_flag flag);
char	*u(va_list args, t_flag flag);
char	*x(va_list args, t_flag flag);
char	*i(va_list args, t_flag flag);
char	*p(va_list args, t_flag flag);
char	*d(va_list args, t_flag flag);
char	*s(va_list args, t_flag flag);
char	*c(va_list args, t_flag flag);
char	*percent(va_list args, t_flag flag);
char	*great_x(va_list args, t_flag flag);

/*
 *	FT_SPLIT_MODULE
 */
t_list	*ft_split_module(const char *ft_format);

/*
 *	FT_STRINGIFY
 */
char	*ft_stringify(t_list *module);

/*
 *	CHECKERS
 */
int		is_conversion(char to_check);
int		is_flag(char to_check);
#endif
