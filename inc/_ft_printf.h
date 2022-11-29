/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/11/29 10:08:01 by bguyot           ###   ########.fr       */
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

# define CONVERSIONS "uxXipd%sc"
# define FLAGS " 0-+#"

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
