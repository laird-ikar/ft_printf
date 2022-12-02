/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 07:34:46 by bguyot            #+#    #+#             */
/*   Updated: 2022/12/02 09:29:27 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include "ft_printf.h"

# ifndef T_FLAG
#  define T_FLAG

typedef struct s_flag
{
	int	conv_type;
	int	padding_type;
	int	positive_sign;
	int	do_alt_form;
	int	min_width;
	int	precision;
}	t_flag;

# endif

# ifndef T_PARSE
#  define T_PARSE

typedef	t_buff	*(t_parse)(va_list, t_flag);

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
t_buff	*expend_arg(va_list args, t_flag flag);
t_buff	*u(va_list args, t_flag flag);
t_buff	*x(va_list args, t_flag flag);
t_buff	*i(va_list args, t_flag flag);
t_buff	*p(va_list args, t_flag flag);
t_buff	*d(va_list args, t_flag flag);
t_buff	*s(va_list args, t_flag flag);
t_buff	*c(va_list args, t_flag flag);
t_buff	*percent(va_list args, t_flag flag);
t_buff	*great_x(va_list args, t_flag flag);
void	apply_width(t_buff *str, int width, int padding_type);

/*
 *	FT_SPLIT_MODULE
 */
t_list	*ft_split_module(const char *ft_format);
void	add_buffer_to_list(
			t_list **lst,
			const char *beg_str,
			const char *end_str
			);

/*
 *	FT_STRINGIFY
 */
t_buff	*ft_stringify(t_list *token);

/*
 *	CHECKERS
 */
int		is_conversion(char to_check);
int		is_flag(char to_check);

/*
 *	FREE_BUFF
 */
void	free_buff(void *buff);

#endif
